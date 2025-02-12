import rasterio
import numpy as np
from shapely.geometry import mapping
from rasterio.features import geometry_mask

# Step 1: Load Raster Data
def load_raster(raster_path):
    with rasterio.open(raster_path) as src:
        bands = [src.read(i) for i in range(1, src.count + 1)]
        profile = src.profile
    return np.stack(bands, axis=-1), profile

# Step 2: Extract Reference Spectra
def extract_reference_spectra(raster, training_shapefile, profile):
    import geopandas as gpd
    training_labels = gpd.read_file(training_shapefile)
    
    reference_spectra = {}
    
    for _, row in training_labels.iterrows():
        class_id = row['class_id']
        geom = [mapping(row['geometry'])]
        
        mask = geometry_mask(
            geom, transform=profile['transform'], invert=True, out_shape=(profile['height'], profile['width'])
        )
        
        masked_pixels = raster[mask]
        mean_spectrum = np.mean(masked_pixels, axis=0)
        reference_spectra[class_id] = mean_spectrum

    return reference_spectra

# Step 3: Spectral Angle Mapping
def spectral_angle(pixel_spectrum, reference_spectrum):
    # Avoid zero vectors
    pixel_norm = np.linalg.norm(pixel_spectrum)
    reference_norm = np.linalg.norm(reference_spectrum)
    
    if pixel_norm == 0 or reference_norm == 0:
        return np.pi  # Maximum angle (180 degrees)

    numerator = np.dot(pixel_spectrum, reference_spectrum)
    denominator = pixel_norm * reference_norm
    
    # Clip to avoid numerical issues with arccos
    cosine_similarity = numerator / denominator
    cosine_similarity = np.clip(cosine_similarity, -1.0, 1.0)
    
    angle = np.arccos(cosine_similarity)
    return angle


def classify_with_sam(raster, reference_spectra):
    rows, cols, bands = raster.shape
    classified_image = np.full((rows, cols), fill_value=255, dtype=np.uint8)  # 255 as nodata

    for i in range(rows):
        for j in range(cols):
            pixel_spectrum = raster[i, j, :]
            angles = {class_id: spectral_angle(pixel_spectrum, ref_spectrum) 
                      for class_id, ref_spectrum in reference_spectra.items()}
            classified_image[i, j] = min(angles, key=angles.get)  # Class with smallest angle

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
    output_path = "classified/sam.tif"

    # Load raster and metadata
    raster, profile = load_raster(raster_path)

    # Extract reference spectra
    print("Extracting reference spectra...")
    reference_spectra = extract_reference_spectra(raster, training_shapefile, profile)

    # Classify raster using SAM
    print("Classifying with SAM...")
    classified_image = classify_with_sam(raster, reference_spectra)

    # Save the classified image
    save_classified_image(classified_image, profile, output_path)
    print(f"Classified image saved to {output_path}")
