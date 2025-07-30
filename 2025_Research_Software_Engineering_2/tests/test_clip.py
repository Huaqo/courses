""""
Unit test verifying that the clip function correctly clips spatial data
using a provided overlay.
"""

import geopandas as gpd
from clip import clip


def test_clip(local_tmp_path):  # pylint: disable=redefined-outer-name
    """Test that clip() writes a clipped GeoDataFrame matching the expected result"""
    input_path = "tests/data/solarparcs.gpkg"
    overlay_path = "tests/data/germany.gpkg"
    expected_path = "tests/data/clip.gpkg"
    output_path = local_tmp_path / "output.gpkg"

    clip(input_path, overlay_path, output_path)
    expected_data = gpd.read_file(expected_path)
    output_data = gpd.read_file(output_path)

    assert len(expected_data) == len(output_data)
