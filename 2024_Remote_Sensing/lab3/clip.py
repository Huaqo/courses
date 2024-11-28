import rasterio
from rasterio.mask import mask
from shapely.geometry import box
import argparse

def get_common_extent(raster1_path, raster2_path):
    """Calculate the common extent (intersection) of two rasters."""
    with rasterio.open(raster1_path) as src1, rasterio.open(raster2_path) as src2:
        bounds1 = src1.bounds
        bounds2 = src2.bounds

        # Calculate the intersection of the extents
        common_bounds = box(
            max(bounds1.left, bounds2.left),
            max(bounds1.bottom, bounds2.bottom),
            min(bounds1.right, bounds2.right),
            min(bounds1.top, bounds2.top),
        )
        return common_bounds

def clip_raster_to_extent(raster_path, extent, output_path):
    """Clip the raster to the provided extent and save it to a new file."""
    with rasterio.open(raster_path) as src:
        # Convert extent to GeoJSON-like dict for rasterio.mask
        geojson_extent = [extent.__geo_interface__]

        # Clip the raster to the extent
        out_image, out_transform = mask(src, geojson_extent, crop=True)
        out_meta = src.meta.copy()

        # Update metadata with new dimensions, transform, and bounds
        out_meta.update({
            "driver": "GTiff",
            "height": out_image.shape[1],
            "width": out_image.shape[2],
            "transform": out_transform
        })

        # Save the clipped raster
        with rasterio.open(output_path, "w", **out_meta) as dest:
            dest.write(out_image)

def main():
    parser = argparse.ArgumentParser(description="Clip two rasters to their common extent.")
    parser.add_argument("raster1", help="Path to the first raster.")
    parser.add_argument("raster2", help="Path to the second raster.")
    parser.add_argument("output1", help="Path to save the clipped first raster.")
    parser.add_argument("output2", help="Path to save the clipped second raster.")

    args = parser.parse_args()

    # Determine the common extent
    common_extent = get_common_extent(args.raster1, args.raster2)

    # Clip both rasters to the common extent
    clip_raster_to_extent(args.raster1, common_extent, args.output1)
    clip_raster_to_extent(args.raster2, common_extent, args.output2)

    print("Rasters clipped successfully!")

if __name__ == "__main__":
    main()
