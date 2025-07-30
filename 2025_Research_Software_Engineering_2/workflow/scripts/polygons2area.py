"""
This script calculates the total area of all geometries in a geospatial file.

It uses the appropriate UTM projection to ensure accurate area calculation.
The result is written to a plain text file in either square kilometers (default)
or square meters, depending on the specified unit.

Usage:
    python polygons2area.py <input_path> <output_path> <unit>

Arguments:
    input_path (str or Path):  Path to the input geospatial file (e.g., GeoPackage, Shapefile).
    output_path (str or Path): Path to the file where the total area will be saved as a string.
    unit (str):                Unit for output area: 'km' (square kilometers) or
                               'm' (square meters).
"""

import os
import sys
import utils
import checks
import logs


def polygons2area(input_path, output_path, unit):
    """
    Computes the total area of polygons in a geospatial file and saves the result.

    The geometry is first projected into the appropriate UTM CRS for accurate area calculation.
    The total area is then summed and converted to the specified unit.

    Args:
        input_path (str or Path): Path to the input geospatial file.
        output_path (str or Path): Path to the output text file.
        unit (str): Unit for the area value: 'km' for square kilometers or 'm' for square meters.

    Returns:
        None: The total area is written as a string to the specified output_path.
    """
    logs.log_processing(os.path.basename(__file__))
    logs.log_parameter("unit", str(unit))
    checks.check_path(input_path)
    checks.check_dir(output_path)
    checks.check_empty(unit)
    checks.check_member(unit, ["m", "km"])

    data = utils.read_gdf(input_path)

    utm_crs = data.estimate_utm_crs()
    projected = data.to_crs(utm_crs)

    area_m2 = projected.area.sum()

    if unit == "km":
        area = area_m2 / 1_000_000
    else:
        area = area_m2
    area_str = f"{area:.2f}"

    utils.save_file(area_str, output_path)
    logs.log_processed(os.path.basename(__file__))


if __name__ == "__main__":
    checks.check_args(4, __doc__)
    polygons2area(sys.argv[1], sys.argv[2], sys.argv[3])
