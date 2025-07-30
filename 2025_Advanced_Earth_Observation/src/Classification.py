import sys
import rasterio
from rasterio.features import rasterize
from rasterio import Affine
import geopandas as gpd
import numpy as np
from sklearn.decomposition import PCA
from sklearn.ensemble import RandomForestClassifier


def classification(path_raster, path_training, path_output):
    raster = rasterio.open(path_raster)
    bands = raster.read()
    # print("Bands shape:", bands.shape)
    meta = raster.meta

    # Flatten spatial dimensions for PCA: (393, 550*572)
    X = bands.reshape(bands.shape[0], -1).T

    # Apply PCA
    n_components = 20
    pca = PCA(n_components=n_components)
    X_pca = pca.fit_transform(X)

    # Reshape back to image cube: (20, 550, 572)
    bands_pca = X_pca.T.reshape(n_components, bands.shape[1], bands.shape[2])

    # Training data
    training = gpd.read_file(path_training)
    if training.crs != raster.crs:
        print(f"Reprojecting training data from {
              training.crs} to {raster.crs}")
        training = training.to_crs(raster.crs)

    # print(training.columns)

    label_raster = rasterize(
        [(geom, class_id) for geom, class_id in zip(
            training.geometry, training.Class_ID)],
        out_shape=(bands.shape[1], bands.shape[2]),
        transform=raster.transform,
        fill=0,
        dtype='int16'
    )

    # Flatten bands and labels
    X_train = bands_pca.reshape(n_components, -1).T
    y_train = label_raster.flatten()

    # Keep only labeled pixels
    mask = y_train > 0
    X_train = X_train[mask]
    y_train = y_train[mask]

    print("Training samples:", X_train.shape)

    clf = RandomForestClassifier(n_estimators=200, random_state=42)
    clf.fit(X_train, y_train)
    print("Classifier trained.")

    # Predict classes for all pixels
    y_pred = clf.predict(X_pca)
    classified = y_pred.reshape(bands.shape[1], bands.shape[2])
    print("Classification completed.")

    # Save classified map
    meta.update({
        "count": 1,
        "dtype": classified.dtype
    })

    with rasterio.open(path_output, "w", **meta) as dst:
        dst.write(classified, 1)

    print(f"Classified map saved to: {path_output}")


if __name__ == "__main__":
    classification(sys.argv[1], sys.argv[2], sys.argv[3])
