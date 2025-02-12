from osgeo import gdal
import numpy as np
import sys
import os
import re
import math

def tif_to_array(path):
    data = gdal.Open(path)
    if data is None:
        raise FileNotFoundError(f"Cannot open file: {path}")
    band = data.GetRasterBand(1)
    array = band.ReadAsArray().astype(np.float32)
    return data, array

def handle_nodata(array):
    clean_array = np.where(array < 0, np.nan, array)
    return clean_array

def reflectance_calc(array, reflectance_mult, reflectance_add, sun_elevation):
    print(f"Reflectance Mult: {reflectance_mult}, Reflectance Add: {reflectance_add}, Sun Elevation: {sun_elevation}")
    print(f"Array Sample Before: {array[:5, :5]}")
    
    result = ((array * reflectance_mult) + reflectance_add) / math.sin(math.radians(sun_elevation))
    
    print(f"Array Sample After: {result[:5, :5]}")
    return result

def save_tif(array, data, output_path):
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

def get_output_path(output_dir, input_path, suffix):
    basename = os.path.basename(input_path)
    basename_no_ext = os.path.splitext(basename)[0]
    path = os.path.join(output_dir, f"{basename_no_ext}_{suffix}.TIF")
    return path

def print_min_max(array, label):
    print(label, " Min:", np.nanmin(array), " Max:", np.nanmax(array))

def get_reflectance_params(band_number, metadata_lines):
    reflectance_mult = None
    reflectance_add = None
    for line in metadata_lines:
        if f"REFLECTANCE_MULT_BAND_{band_number}" in line:
            variable, value = line.split(" = ")
            reflectance_mult = float(value.strip())
        if f"REFLECTANCE_ADD_BAND_{band_number}" in line:
            variable, value = line.split(" = ")
            reflectance_add = float(value.strip())
    if reflectance_mult is None or reflectance_add is None:
        raise ValueError(f"Reflectance parameters not found for band {band_number} in metadata.")
    return reflectance_mult, reflectance_add

def process_bands(band_paths, metadata_path, output_dir):
    with open(metadata_path, "r") as file:
        metadata_lines = file.readlines()

    sun_elevation = None
    for line in metadata_lines:
        if "SUN_ELEVATION" in line:
            variable, value = line.split(" = ")
            sun_elevation = float(value.strip())
            break

    if sun_elevation is None:
        raise ValueError("Sun elevation not found in metadata.")

    print(f"Sun Elevation: {sun_elevation}, Sun Elevation Radians: {math.radians(sun_elevation)}")

    for band_path in band_paths:
        band_number = int(re.search(r'_B(\d+)', band_path).group(1))
        data, array = tif_to_array(band_path)
        array = handle_nodata(array)

        reflectance_mult, reflectance_add = get_reflectance_params(band_number, metadata_lines)

        reflectance = reflectance_calc(array, reflectance_mult, reflectance_add, sun_elevation)

        if not os.path.exists(output_dir):
            os.makedirs(output_dir)

        output_path = get_output_path(output_dir, band_path, f"toa")
        save_tif(reflectance, data, output_path)

        print_min_max(reflectance, f"Band {band_number} Reflectance")

def main():
    if len(sys.argv) < 4:
        print("Usage: python3 script.py <metadata_path> <output_directory> <band_paths...>")
        sys.exit(1)

    metadata_path = sys.argv[1]
    output_dir = sys.argv[2]
    band_paths = sys.argv[3:]

    process_bands(band_paths, metadata_path, output_dir)

if __name__ == "__main__":
    main()
