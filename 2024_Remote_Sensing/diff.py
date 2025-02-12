import rasterio
from rasterio.warp import reproject, Resampling
import numpy as np
import argparse

def resample_raster_to_match(reference_path, target_path, output_path):
    """Resample the target raster to match the resolution, extent, and CRS of the reference raster."""
    with rasterio.open(reference_path) as ref:
        ref_transform = ref.transform
        ref_crs = ref.crs
        ref_width = ref.width
        ref_height = ref.height
        ref_nodata = ref.nodata or -9999

        with rasterio.open(target_path) as target:
            target_nodata = target.nodata or -9999
            profile = target.profile
            profile.update(
                transform=ref_transform,
                crs=ref_crs,
                width=ref_width,
                height=ref_height,
                nodata=ref_nodata
            )

            # Resample target raster
            with rasterio.open(output_path, "w", **profile) as output:
                for i in range(1, target.count + 1):
                    reproject(
                        source=rasterio.band(target, i),
                        destination=rasterio.band(output, i),
                        src_transform=target.transform,
                        src_crs=target.crs,
                        dst_transform=ref_transform,
                        dst_crs=ref_crs,
                        resampling=Resampling.bilinear,
                    )

def calculate_difference(raster1_path, raster2_resampled_path, output_path):
    """Calculate the difference between two aligned rasters."""
    with rasterio.open(raster1_path) as src1:
        raster1 = src1.read(1)
        nodata1 = src1.nodata or -9999
        profile = src1.profile

    with rasterio.open(raster2_resampled_path) as src2:
        raster2 = src2.read(1)
        nodata2 = src2.nodata or -9999

    # Replace nodata values with NaN for calculation
    raster1 = np.where(raster1 == nodata1, np.nan, raster1)
    raster2 = np.where(raster2 == nodata2, np.nan, raster2)

    # Compute difference
    difference = raster1 - raster2

    # Replace NaN with nodata for saving
    difference[np.isnan(difference)] = -9999

    # Update metadata to include nodata
    profile.update(nodata=-9999)

    # Save the difference raster
    with rasterio.open(output_path, "w", **profile) as dst:
        dst.write(difference, 1)

def main():
    parser = argparse.ArgumentParser(description="Resample a raster and calculate the difference.")
    parser.add_argument("reference_raster", help="Path to the reference raster.")
    parser.add_argument("target_raster", help="Path to the target raster to be resampled.")
    parser.add_argument("aligned_raster", help="Path to save the resampled (aligned) raster.")
    parser.add_argument("difference_raster", help="Path to save the difference raster.")

    args = parser.parse_args()

    # Resample raster 2 to match raster 1
    resample_raster_to_match(args.reference_raster, args.target_raster, args.aligned_raster)

    # Calculate the difference
    calculate_difference(args.reference_raster, args.aligned_raster, args.difference_raster)

    print("Aligned raster and difference raster created successfully!")

if __name__ == "__main__":
    main()
