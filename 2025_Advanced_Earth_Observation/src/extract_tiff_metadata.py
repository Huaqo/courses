import rasterio
import os
import csv
from rasterio.warp import transform_bounds
from pyproj import Geod


def extract_tiff_metadata(tiff_path, output_csv_path):
    """
    Extracts metadata from a TIFF file and writes it to a CSV file.

    :param tiff_path: Path to the TIFF file
    :param output_csv_path: Path to save the metadata CSV file
    """
    try:
        with rasterio.open(tiff_path) as dataset:
            pixel_size_x, pixel_size_y = dataset.res
            crs = dataset.crs
            geod = Geod(ellps="WGS84")

            if crs.is_projected:
                # Units are already linear (e.g., meters)
                crs_unit = crs.linear_units
                pixel_area = abs(pixel_size_x * pixel_size_y)
                pixel_size_x_m = pixel_size_x
                pixel_size_y_m = pixel_size_y
            else:
                # CRS is geographic (degrees), compute approximate linear size
                bounds = dataset.bounds

                # Approximate pixel size X in meters
                lon1, lat1 = bounds.left, bounds.bottom
                lon2, lat2 = bounds.left + pixel_size_x, bounds.bottom
                distance_x, _, _ = geod.inv(lon1, lat1, lon2, lat2)

                # Approximate pixel size Y in meters
                lon3, lat3 = bounds.left, bounds.bottom
                lon4, lat4 = bounds.left, bounds.bottom + pixel_size_y
                distance_y, _, _ = geod.inv(lon3, lat3, lon4, lat4)

                pixel_size_x_m = abs(distance_x)
                pixel_size_y_m = abs(distance_y)
                crs_unit = "meters"
                pixel_area = pixel_size_x_m * pixel_size_y_m

            meta_info = {
                "Filename": os.path.basename(tiff_path),
                "Width (pixels)": dataset.width,
                "Height (pixels)": dataset.height,
                "Number of Bands": dataset.count,
                "Coordinate Reference System (CRS)": str(crs),
                "Pixel Area": f"{pixel_area:.1f} {crs_unit}²",
            }

            # Write metadata to CSV file
            with open(output_csv_path, mode='w', newline='') as csvfile:
                writer = csv.writer(csvfile)
                writer.writerow(["Key", "Value"])
                for key, value in meta_info.items():
                    writer.writerow([key, value])

        print(f"Metadata written to {output_csv_path}")

    except Exception as e:
        print(f"Error: {e}")


# Example usage
if __name__ == "__main__":
    tiff_file = "example.tif"          # Path to your TIFF file
    output_file = "metadata_output.csv"  # Path to output CSV file
    extract_tiff_metadata(tiff_file, output_file)
