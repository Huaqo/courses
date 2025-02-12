import argparse
import rasterio
import numpy as np
from sklearn.cluster import KMeans

def main(input_file, output_file, n_clusters):
    with rasterio.open(input_file) as src:
        raster_data = src.read()
        profile = src.profile

    rows, cols = raster_data.shape[1], raster_data.shape[2]
    raster_data_reshaped = raster_data.reshape(raster_data.shape[0], -1).T

    kmeans = KMeans(n_clusters=n_clusters, random_state=0)
    kmeans.fit(raster_data_reshaped)
    cluster_labels = kmeans.labels_

    classified_raster = cluster_labels.reshape(rows, cols)

    with rasterio.open(
        output_file, 'w',
        driver='GTiff',
        height=rows,
        width=cols,
        count=1,
        dtype=classified_raster.dtype,
        crs=src.crs,
        transform=src.transform,
    ) as dst:
        dst.write(classified_raster, 1)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Unsupervised classification for raster data.")
    parser.add_argument("input_file", type=str, help="Path to the input .tif file.")
    parser.add_argument("output_file", type=str, help="Path to save the classified .tif file.")
    parser.add_argument("--n_clusters", type=int, default=4, help="Number of clusters for classification (default: 4).")
    args = parser.parse_args()

    main(args.input_file, args.output_file, args.n_clusters)
