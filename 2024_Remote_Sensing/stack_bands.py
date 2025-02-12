import rasterio
import numpy as np
import argparse

def stack_bands(input_files, output_file):
    bands = []
    metadata = None
    for band_file in input_files:
        with rasterio.open(band_file) as src:
            if metadata is None:
                metadata = src.meta
                metadata.update(count=len(input_files))
            bands.append(src.read(1))

    stacked_data = np.stack(bands)

    with rasterio.open(output_file, 'w', **metadata) as dst:
        for i in range(stacked_data.shape[0]):
            dst.write(stacked_data[i, :, :], i + 1)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Stack multiple raster bands into a single .tif file.")
    parser.add_argument("input_files", nargs='+', help="Paths to the input .tif files (one for each band).")
    parser.add_argument("output_file", type=str, help="Path to save the stacked .tif file.")
    args = parser.parse_args()

    stack_bands(args.input_files, args.output_file)
