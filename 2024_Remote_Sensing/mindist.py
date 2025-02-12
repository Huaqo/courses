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

# Step 2: Extract Reference Spectra
def extract_reference_spectra(raster, training_shapefile, profile):
    training_labels = gpd.read_file(training_shapefile)
    
    reference_spectra = {}
    
    for _, row in training_labels.iterrows():
        class_id = row['class_id']
        geom = [mapping(row['geometry'])]
        
        mask = geometry_mask(
            geom, transform=profile['transform'], invert=True, out_shape=(profile['height'], profile['width'])
        )
        
        masked_pixels = raster[mask]
        mean_spectrum = np.mean(masked_pixels, axis=0)  # Calculate mean spectrum for the class
        reference_spectra[class_id] = mean_spectrum

    return reference_spectra

# Step 3: Minimum Distance Classification
def minimum_distance(pixel_spectrum, reference_spectra):
    distances = {class_id: np.linalg.norm(pixel_spectrum - ref_spectrum) 
                 for class_id, ref_spectrum in reference_spectra.items()}
    return min(distances, key=distances.get)  # Return the class with the smallest distance

def classify_with_min_distance(raster, reference_spectra):
    rows, cols, bands = raster.shape
    classified_image = np.full((rows, cols), fill_value=255, dtype=np.uint8)  # 255 as nodata

    for i in range(rows):
        for j in range(cols):
            pixel_spectrum = raster[i, j, :]
            classified_image[i, j] = minimum_distance(pixel_spectrum, reference_spectra)

    return classified_image

# Step 4: Save Classified Image
def save_classified_image(classified_image, profile, output_path):
    profile.update(count=1, dtype=rasterio.uint8, nodata=255)
    with rasterio.open(output_path, "w", **profile) as dst:
        dst.write(classified_image, 1)

# Main Execution
if __name__ == "__main__":
    # File paths
    raster_path = "stacked/stacked.tif"
    training_shapefile = "training/training.shp"
    output_path = "classified/mindist.tif"

    # Load raster and metadata
    raster, profile = load_raster(raster_path)

    # Extract reference spectra
    print("Extracting reference spectra...")
    reference_spectra = extract_reference_spectra(raster, training_shapefile, profile)

    # Classify raster using Minimum Distance
    print("Classifying with Minimum Distance...")
    classified_image = classify_with_min_distance(raster, reference_spectra)

    # Save the classified image
    save_classified_image(classified_image, profile, output_path)
    print(f"Classified image saved to {output_path}")
