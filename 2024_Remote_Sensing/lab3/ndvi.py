from osgeo import gdal
import numpy as np
import sys
import os 
import re

def tif_to_array(path):
    data = gdal.Open(path)
    if data is None:
        raise FileNotFoundError(f"Cannot open file: {path}")
    band = data.GetRasterBand(1)
    array = band.ReadAsArray().astype(np.float32)
    return data, array

def handle_nodata(array):
    # Normalize the reflectance values to [0, 1]
    normalized_array = array / 10000.0
    # Replace out-of-range values with NaN
    clean_array = np.where((normalized_array < 0) | (normalized_array > 1), np.nan, normalized_array)
    return clean_array


def ndvi_calc(NIR,RED):
    ndvi_array = (NIR - RED) / (NIR + RED + 1e-10)
    return ndvi_array

def save_tif(array,data,output_path):
    driver = gdal.GetDriverByName('GTiff')
    rows, cols = array.shape
    out_data = driver.Create(output_path, cols, rows, 1, gdal.GDT_Float32)
    out_data.SetGeoTransform(data.GetGeoTransform())
    out_data.SetProjection(data.GetProjection())
    out_band = out_data.GetRasterBand(1)
    out_band.WriteArray(array)
    out_band.SetNoDataValue(-9999)
    out_band.FlushCache()
    out_data = None

def get_output_path(output_dir,input_path):
    basename = os.path.basename(input_path)
    basename_no_ext = os.path.splitext(basename)[0]
    basename_no_ext = re.sub(r'_B[1-9]|_B10|_B11', '', basename_no_ext)
    path = os.path.join(output_dir, f"{basename_no_ext}_ndvi.TIF")
    return path

def print_min_max(array, label):
    print(label," Min:", np.nanmin(array), " Max:",np.nanmax(array))

def main():
    if len(sys.argv) != 4:
        print("Usage: python3 script.py <red_band_path> <nir_band_path> <output_directory>")
        sys.exit(1)

    red_path = sys.argv[1]
    nir_path = sys.argv[2]
    output_dir = sys.argv[3]

    red_data, red_array = tif_to_array(red_path)
    nir_data, nir_array = tif_to_array(nir_path)
    red_array = handle_nodata(red_array)
    nir_array = handle_nodata(nir_array)

    ndvi_array = ndvi_calc(nir_array, red_array)

    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    output_path = get_output_path(output_dir,red_path)

    save_tif(ndvi_array, red_data, output_path)

    print_min_max(red_array, "RED")
    print_min_max(nir_array, "NIR")
    print_min_max(ndvi_array, "NDVI")

if __name__ == "__main__":
    main()