import argparse
import rasterio
import geopandas as gpd
import numpy as np
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report
from rasterio.features import geometry_mask
from shapely.geometry import mapping

# Step 1: Load the Raster Data
def load_raster(raster_path):
    with rasterio.open(raster_path) as src:
        bands = [src.read(i) for i in range(1, src.count + 1)]
        profile = src.profile
    return np.stack(bands, axis=-1), profile

# Step 2: Extract Features and Labels from Training Data
def extract_training_data(raster, training_shapefile, profile):
    training_labels = gpd.read_file(training_shapefile)

    features = []
    labels = []

    for _, row in training_labels.iterrows():
        class_id = row['Class']  # Ensure 'class_id' column exists in the shapefile
        geom = [mapping(row['geometry'])]

        mask = geometry_mask(
            geom, transform=profile['transform'], invert=True, out_shape=(profile['height'], profile['width'])
        )

        masked_pixels = raster[mask]
        features.append(masked_pixels)
        labels.append(np.full(masked_pixels.shape[0], class_id))

    return np.vstack(features), np.hstack(labels)

# Step 3: Train the Random Forest Classifier
def train_classifier(features, labels):
    X_train, X_test, y_train, y_test = train_test_split(features, labels, test_size=0.3, random_state=42)

    classifier = RandomForestClassifier(n_estimators=100, random_state=42)
    classifier.fit(X_train, y_train)

    y_pred = classifier.predict(X_test)
    print("Classification Report:")
    print(classification_report(y_test, y_pred))

    return classifier

# Step 4: Classify the Entire Raster
def classify_raster(raster, classifier, profile, output_path):
    rows, cols, bands = raster.shape
    flattened_data = raster.reshape(-1, bands)

    predictions = classifier.predict(flattened_data)
    classified_image = predictions.reshape(rows, cols)

    profile.update(
        count=1,
        dtype=rasterio.uint8,
        nodata=255
    )

    with rasterio.open(output_path, "w", **profile) as dst:
        dst.write(classified_image.astype(rasterio.uint8), 1)

    return classified_image

def main():
    parser = argparse.ArgumentParser(description="Random Forest classification of a raster using training shapefile.")
    parser.add_argument('--raster_path', required=True, help='Path to the input raster file.')
    parser.add_argument('--training_shapefile', required=True, help='Path to the training shapefile.')
    parser.add_argument('--output_path', required=True, help='Path for the classified raster output.')
    args = parser.parse_args()

    # Load raster and metadata
    print("Loading raster...")
    raster, profile = load_raster(args.raster_path)

    # Extract training data
    print("Extracting training data...")
    features, labels = extract_training_data(raster, args.training_shapefile, profile)

    # Train the classifier
    print("Training the classifier...")
    classifier = train_classifier(features, labels)

    # Classify the raster
    print("Classifying the raster...")
    classify_raster(raster, classifier, profile, args.output_path)
    print("Classification complete. Output saved to:", args.output_path)

if __name__ == "__main__":
    main()
