import rasterio
import numpy as np
import pandas as pd


def get_class_frequency(raster_path, metadata):
    with rasterio.open(raster_path) as raster:
        band = raster.read(1)

    nodata = raster.nodata
    if nodata is not None:
        band = band[band != nodata]
    else:
        band = band[~np.isnan(band)]

    values, counts = np.unique(band, return_counts=True)
    df = pd.DataFrame({'class_id': values, 'count': counts})
    df = df.merge(metadata, on='class_id', how='left')
    df = df[['class_name', 'count']]

    return df
