"""
Perform spatial clipping of geospatial data using GeoPandas.

This script reads an input geospatial file and an overlay file,
clips the input to the overlay boundaries, and saves the clipped
result as a GeoPackage file.

Usage:
    python clip.py <input_path> <overlay_path> <output_path>

Arguments:
    input_path (str or Path):       Path to the input geospatial file (e.g., GeoPackage, shapefile).
    overlay_path (str or Path):     Path to the overlay geospatial file used for clipping.
    output_path (str or Path):      Path to save the clipped output as a GeoPackage (.gpkg).
"""

import os
import sys
import geopandas as gpd
import utils
import checks
import logs


def clip(input_path, overlay_path, output_path):
    """
    Clips input to overlay and exports result. Includes Errorhandling.

    Performs spatial clipping of input data using the geometry boundaries
    from the overlay data, and exports the clipped result to a GeoPackage.

    Arguments:
        input_path (str or Path):   Path to the input file (.gpkg).
        overlay_path (str or Path): Path to the clipping layer (.gpkg).
        output_path (str or Path):  Path to save the clipped output (.gpkg).

    Returns:
        None: The processed clipped output is saved to `output_path`.
    """
    logs.log_processing(os.path.basename(__file__))
    logs.log_intensive()
    checks.check_path(input_path)
    checks.check_path(overlay_path)
    checks.check_dir(output_path)

    input_data = utils.read_gdf(input_path)
    overlay_data = utils.read_gdf(overlay_path)

    checks.check_crs(input_data.crs, overlay_data.crs)

    clipped_data = gpd.clip(input_data, overlay_data)
    checks.check_gdf(clipped_data)
    utils.save_gdf(clipped_data, output_path)
    logs.log_processed(os.path.basename(__file__))


if __name__ == "__main__":
    checks.check_args(4, __doc__)
    clip(sys.argv[1], sys.argv[2], sys.argv[3])
