import rasterio
import geopandas as gpd
from sklearn.metrics import confusion_matrix, classification_report
import numpy as np


def accuracy_assessment(classified_raster_path, reference_points_path, true_class_field):
    """
    Perform accuracy assessment of classified raster using reference points.

    Parameters:
    - classified_raster_path: str, path to classified TIFF raster file.
    - reference_points_path: str, path to reference points vector file (GeoJSON or Shapefile).
    - true_class_field: str, name of the attribute field in reference data containing true class labels.

    Returns:
    - dict with confusion matrix, classification report, overall accuracy, and kappa coefficient.
    """

    # Load raster
    raster = rasterio.open(classified_raster_path)

    # Load reference points
    gdf = gpd.read_file(reference_points_path)

    # Reproject reference points to raster CRS if needed
    if gdf.crs != raster.crs:
        gdf = gdf.to_crs(raster.crs)

    # Extract raster values at point locations
    coords = [(geom.x, geom.y) for geom in gdf.geometry]
    raster_vals = []
    for val in raster.sample(coords):
        if val.size > 0 and val[0] is not None:
            raster_vals.append(val[0])
        else:
            raster_vals.append(np.nan)

    gdf['predicted_class'] = raster_vals

    # Drop points where raster value could not be sampled (e.g., outside raster extent)
    gdf = gdf.dropna(subset=['predicted_class'])

    # Convert predicted_class to int (if float)
    gdf['predicted_class'] = gdf['predicted_class'].astype(int)

    y_true = gdf[true_class_field].values
    y_pred = gdf['predicted_class'].values

    print("Unique classes in y_true:", np.unique(y_true))
    print("Unique classes in y_pred:", np.unique(y_pred))
    print("Anzahl Samples:", len(y_true))

    # Compute confusion matrix
    cm = confusion_matrix(y_true, y_pred)

    # Compute classification report (precision, recall, f1-score)
    report = classification_report(y_true, y_pred, output_dict=True)

    # Overall accuracy
    overall_accuracy = np.trace(cm) / np.sum(cm)

    # Kappa coefficient calculation
    total = np.sum(cm)
    sum_rows = np.sum(cm, axis=1)
    sum_cols = np.sum(cm, axis=0)
    expected_accuracy = np.sum(sum_rows * sum_cols) / (total ** 2)
    kappa = (overall_accuracy - expected_accuracy) / (1 - expected_accuracy)

    # Print summary
    print("Confusion Matrix:\n", cm)
    print(f"Overall Accuracy: {overall_accuracy:.4f}")
    print(f"Kappa Coefficient: {kappa:.4f}")
    print("Classification Report (per class):")
    for cls, metrics in report.items():
        if cls not in ['accuracy', 'macro avg', 'weighted avg']:
            print(f"Class {cls}: Precision={metrics['precision']:.3f}, Recall={
                  metrics['recall']:.3f}, F1-score={metrics['f1-score']:.3f}")

    return {
        'confusion_matrix': cm,
        'classification_report': report,
        'overall_accuracy': overall_accuracy,
        'kappa_coefficient': kappa
    }
