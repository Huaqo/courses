import sys
import rasterio
import numpy as np

def normalize_tif(input_tif, output_tif):
    with rasterio.open(input_tif) as src:
        data = src.read(1)  # Reading the first band
        profile = src.profile

        # Handle potential NoData values
        valid_mask = data != src.nodata if src.nodata is not None else np.ones_like(data, dtype=bool)
        data_min, data_max = data[valid_mask].min(), data[valid_mask].max()

        # Normalize data
        normalized_data = (data - data_min) / (data_max - data_min)
        normalized_data[~valid_mask] = src.nodata  # Retain NoData values

        profile.update(dtype=rasterio.float32)

        with rasterio.open(output_tif, 'w', **profile) as dst:
            dst.write(normalized_data.astype(rasterio.float32), 1)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 norm.py <input_tif> <output_tif>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    normalize_tif(input_file, output_file)
    print(f"Normalized file saved to {output_file}")
