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

def get_radiance_params(band_number, metadata_lines):
    radiance_mult = None
    radiance_add = None
    for line in metadata_lines:
        if f"RADIANCE_MULT_BAND_{band_number}" in line:
            _, value = line.split(" = ")
            radiance_mult = float(value.strip())
        if f"RADIANCE_ADD_BAND_{band_number}" in line:
            _, value = line.split(" = ")
            radiance_add = float(value.strip())
    if radiance_mult is None or radiance_add is None:
        raise ValueError(f"Radiance parameters not found for band {band_number} in metadata.")
    return radiance_mult, radiance_add

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

def process_bands(bands, metadata_path, output_dir):
    # Read metadata
    with open(metadata_path, "r") as file:
        metadata_lines = file.readlines()

    # Extract sun elevation (optional for radiance, included for debugging)
    sun_elevation = None
    for line in metadata_lines:
        if "SUN_ELEVATION" in line:
            _, value = line.split(" = ")
            sun_elevation = float(value.strip())
            break

    # Debugging sun elevation value
    if sun_elevation is not None:
        print(f"Sun Elevation: {sun_elevation}, Sun Elevation Radians: {math.radians(sun_elevation)}")

    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    # Process each band
    for band_data in bands:
        band_number, band_path = band_data[0], band_data[1]

        # Load the band data
        data, array = tif_to_array(band_path)

        # Get radiance parameters for the band
        radiance_mult, radiance_add = get_radiance_params(band_number, metadata_lines)

        # Calculate radiance
        radiance_array = (array * radiance_mult) + radiance_add

        # Save the Top of Atmosphere (TOA) radiance
        output_path = get_output_path(output_dir, band_path, "toa_radiance")
        save_tif(radiance_array, data, output_path)

        # Print min and max for the radiance band
        print_min_max(radiance_array, f"Band {band_number} Radiance")

def main():
    print(f"Number of arguments received: {len(sys.argv) - 1}")
    print("Arguments:", sys.argv)
    if len(sys.argv) < 4:
        print("Usage: python3 script.py <metadata_path> <output_directory> <band_paths...>")
        sys.exit(1)

    metadata_path = sys.argv[1]
    output_dir = sys.argv[2]
    band_paths = sys.argv[3:]

    bands = [(int(re.search(r'B(\d+)', path).group(1)), path) for path in band_paths]

    process_bands(bands, metadata_path, output_dir)

if __name__ == "__main__":
    main()
