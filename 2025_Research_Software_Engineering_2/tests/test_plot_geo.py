"""Unit tests for the plot_geo module."""

import os
from plot_geo import plot_geo


def test_plot_geo(local_tmp_path):  # pylint: disable=redefined-outer-name
    """Test that gpkg2png generates a non-empty PNG file"""
    data_path = "tests/data/solarparcs.gpkg"
    base_path = "tests/data/germany.gpkg"
    output_path = local_tmp_path / "output.png"
    title = "Test Map"

    plot_geo(data_path, base_path, output_path, title)

    assert os.path.exists(output_path)
    assert os.path.getsize(output_path) > 0
