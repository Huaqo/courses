"""Unit tests for the polygons2area function in src.polygons2area.py"""

import os
from polygons2area import polygons2area


def test_polygons2area(local_tmp_path):  # pylint: disable=redefined-outer-name
    """
    Test that polygons2area computes the area of input polygons and writes the result
    to a non-empty output text file.
    """
    input_path = "tests/data/clip.gpkg"
    output_path = local_tmp_path / "output.txt"
    unit = "m"

    polygons2area(input_path, output_path, unit)

    assert os.path.exists(output_path)
    assert os.path.getsize(output_path) > 0
