import sys
import os
from osgeo import gdal
import numpy as np
import math

def load_metadata(metadata_path):
    K_CONSTANTS = {}
    with open(metadata_path, "r") as file:
        metadata_lines = file.readlines()
        for line in metadata_lines:
            if "K1_CONSTANT_BAND_10" in line or "K2_CONSTANT_BAND_10" in line or \
               "K1_CONSTANT_BAND_11" in line or "K2_CONSTANT_BAND_11" in line:
                variable, value = line.split(" = ")
                K_CONSTANTS[variable.strip()] = float(value.strip())
    return K_CONSTANTS

def load_band(band_path):
    band_data = gdal.Open(band_path)
    band = band_data.GetRasterBand(1)
    band_array = band.ReadAsArray().astype(np.float32)
    no_data_value = band.GetNoDataValue()
    band_array = np.where(band_array == no_data_value, np.nan, band_array)
    return band_data, band_array

def calculate_surface_temperature(band_array, K1_CONSTANT, K2_CONSTANT):
    epsilon = 1e-10
    result_array = (K2_CONSTANT / np.log((K1_CONSTANT / (band_array + epsilon)) + 1)) - 273.15
    return result_array

def save_result(output_directory, band_path, result_array, band_data):
    if not os.path.exists(output_directory):
        os.makedirs(output_directory)
    driver = gdal.GetDriverByName('GTiff')
    rows, cols = result_array.shape
    band_filename = os.path.basename(band_path)
    output_filename = os.path.splitext(band_filename)[0] + '_surfacetemp.TIF'
    output_path = os.path.join(output_directory, output_filename)
    out_data = driver.Create(output_path, cols, rows, 1, gdal.GDT_Float32)
    out_data.SetGeoTransform(band_data.GetGeoTransform())
    out_data.SetProjection(band_data.GetProjection())
    out_band = out_data.GetRasterBand(1)
    out_band.WriteArray(result_array)
    out_band.SetNoDataValue(0)
    out_band.FlushCache()
    out_data = None

def main():
    metadata_path = sys.argv[1]
    band_paths = {
        'BAND_10': sys.argv[2],
        'BAND_11': sys.argv[3]
    }
    output_directory = sys.argv[4]

    # Load metadata
    K_CONSTANTS = load_metadata(metadata_path)
    print(K_CONSTANTS)

    # Process each band
    for band_key, band_path in band_paths.items():
        # Load band
        band_data, band_array = load_band(band_path)
        
        # Get K1 and K2 constants
        K1_CONSTANT = K_CONSTANTS[f'K1_CONSTANT_{band_key}']
        K2_CONSTANT = K_CONSTANTS[f'K2_CONSTANT_{band_key}']

        # Calculate surface temperature
        result_array = calculate_surface_temperature(band_array, K1_CONSTANT, K2_CONSTANT)

        # Save the result
        save_result(output_directory, band_path, result_array, band_data)

        # Print min and max of the arrays
        print(f"{band_key} Min, Max:", np.nanmin(band_array), np.nanmax(band_array))
        print(f"{band_key} Surface Temp Min, Max:", np.nanmin(result_array), np.nanmax(result_array))

if __name__ == "__main__":
    main()

