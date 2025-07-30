import sys
import rasterio
from rasterio.mask import mask
import geopandas as gpd


def clip_tiff(tiff_path, gpkg_path, output_path):
    vector = gpd.read_file(gpkg_path)

    with rasterio.open(tiff_path) as src:
        if vector.crs != src.crs:
            vector = vector.to_crs(src.crs)

        geometries = [feature["geometry"]
                      for feature in vector.__geo_interface__['features']]

        out_image, out_transform = mask(src, geometries, crop=True)
        out_meta = src.meta.copy()

        out_meta.update({
            "driver": "GTiff",
            "height": out_image.shape[1],
            "width": out_image.shape[2],
            "transform": out_transform
        })

    with rasterio.open(output_path, "w", **out_meta) as dest:
        dest.write(out_image)

    print(f"Clipped raster saved to: {output_path}")


if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python clip_tiff.py <input.tif> <input.gpkg> <output.tif>")
        sys.exit(1)

    tiff_file = sys.argv[1]
    gpkg_file = sys.argv[2]
    output_file = sys.argv[3]

    clip_tiff(tiff_file, gpkg_file, output_file)
