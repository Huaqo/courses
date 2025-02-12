import rasterio
import numpy as np
from shapely.geometry import mapping
from rasterio.features import geometry_mask
import geopandas as gpd

# Step 1: Load Raster Data
def load_raster(raster_path):
    with rasterio.open(raster_path) as src:
        bands = [src.read(i) for i in range(1, src.count + 1)]
        profile = src.profile
    return np.stack(bands, axis=-1), profile

# Step 2: Extract Training Data
def extract_training_data(raster, training_shapefile, profile):
    training_labels = gpd.read_file(training_shapefile)
    
    class_data = {}
    for _, row in training_labels.iterrows():
        class_id = row['class_id']
        geom = [mapping(row['geometry'])]
        
        mask = geometry_mask(
            geom, transform=profile['transform'], invert=True, out_shape=(profile['height'], profile['width'])
        )
        
        masked_pixels = raster[mask]
        if class_id not in class_data:
            class_data[class_id] = []
        class_data[class_id].append(masked_pixels)

    # Aggregate class data
    for class_id in class_data.keys():
        class_data[class_id] = np.vstack(class_data[class_id])
    
    return class_data

# Step 3: Calculate Mean and Covariance for Each Class
def compute_statistics(class_data):
    statistics = {}
    for class_id, pixels in class_data.items():
        mean_vector = np.mean(pixels, axis=0)
        covariance_matrix = np.cov(pixels, rowvar=False)
        statistics[class_id] = {
            "mean": mean_vector,
            "covariance": covariance_matrix
        }
    return statistics

# Step 4: Maximum Likelihood Calculation
def calculate_likelihood(pixel, mean, covariance):
    # Multivariate normal distribution likelihood
    dim = len(pixel)
    det_cov = np.linalg.det(covariance)
    inv_cov = np.linalg.inv(covariance)
    
    diff = pixel - mean
    exponent = -0.5 * np.dot(diff.T, np.dot(inv_cov, diff))
    likelihood = (1.0 / ((2 * np.pi) ** (dim / 2) * (det_cov ** 0.5))) * np.exp(exponent)
    return likelihood

def classify_with_maximum_likelihood(raster, statistics):
    rows, cols, bands = raster.shape
    classified_image = np.full((rows, cols), fill_value=255, dtype=np.uint8)  # 255 as nodata

    for i in range(rows):
        for j in range(cols):
            pixel_spectrum = raster[i, j, :]
            likelihoods = {
                class_id: calculate_likelihood(pixel_spectrum, stats["mean"], stats["covariance"])
                for class_id, stats in statistics.items()
            }
            classified_image[i, j] = max(likelihoods, key=likelihoods.get)  # Class with maximum likelihood

    return classified_image

# Step 5: Save Classified Image
def save_classified_image(classified_image, profile, output_path):
    profile.update(count=1, dtype=rasterio.uint8, nodata=255)
    with rasterio.open(output_path, "w", **profile) as dst:
        dst.write(classified_image, 1)

# Main Execution
if __name__ == "__main__":
    # File paths
    raster_path = "stacked/stacked.tif"
    training_shapefile = "training/training.shp"
    output_path = "classified/maxlike.tif"

    # Load raster and metadata
    raster, profile = load_raster(raster_path)

    # Extract training data
    print("Extracting training data...")
    class_data = extract_training_data(raster, training_shapefile, profile)

    # Compute class statistics
    print("Computing class statistics...")
    statistics = compute_statistics(class_data)

    # Classify raster using Maximum Likelihood
    print("Classifying with Maximum Likelihood...")
    classified_image = classify_with_maximum_likelihood(raster, statistics)

    # Save the classified image
    save_classified_image(classified_image, profile, output_path)
    print(f"Classified image saved to {output_path}")
