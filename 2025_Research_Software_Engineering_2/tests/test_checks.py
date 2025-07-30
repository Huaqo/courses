"""
Unit tests for the `checks` module, which validate various input verification functions.
"""
import sys
import pandas as pd
import geopandas as gpd
from shapely.geometry import Point
import pytest
import checks


def test_check_empty():
    """
    Test that check_empty raises ValueError for empty or None inputs, and
    passes for valid inputs.
    """
    checks.check_empty("hello")
    checks.check_empty([1, 2, 3])

    try:
        checks.check_empty("")
    except ValueError:
        pass
    else:
        assert False, "Expected ValueError for empty string"

    try:
        checks.check_empty([])
    except ValueError:
        pass
    else:
        assert False, "Expected ValueError for empty list"

    try:
        checks.check_empty(None)
    except ValueError:
        pass
    else:
        assert False, "Expected ValueError for None"


def test_check_path(local_tmp_path):
    """
    Test that check_path passes for existing files and raises FileNotFoundError
    for missing files.
    """
    tmp_file = local_tmp_path / "file.txt"
    tmp_file.write_text("test")
    checks.check_path(str(tmp_file))

    with pytest.raises(FileNotFoundError):
        checks.check_path(str(local_tmp_path / "nonexistent.txt"))


def test_check_dir(local_tmp_path):
    """Test that check_dir verifies if the directory part of a path exists."""
    some_file = local_tmp_path / "some_file.txt"
    checks.check_dir(str(some_file))

    with pytest.raises(FileNotFoundError):
        checks.check_dir("/non/existing/parent_dir/file.txt")


def test_check_args():
    """Test that check_args validates the number of command-line arguments."""
    original_argv = sys.argv
    sys.argv = ['prog', 'arg1', 'arg2']

    checks.check_args(3, "Wrong args count")

    try:
        checks.check_args(2, "Wrong args count")
    except RuntimeError:
        pass
    else:
        assert False, "Expected RuntimeError for wrong arg count"

    sys.argv = original_argv


def test_check_crs():
    """
    Test that check_crs passes for matching CRS values and raises ValueError
    on mismatch.
    """
    checks.check_crs("EPSG:4326", "EPSG:4326")

    try:
        checks.check_crs("EPSG:4326", "EPSG:3857")
    except ValueError:
        pass
    else:
        assert False, "Expected ValueError for CRS mismatch"


def test_check_df():
    """Test that check_df validates input as non-empty pandas DataFrame with non-NaN data."""
    df = pd.DataFrame({"a": [1, 2]})
    checks.check_df(df)

    try:
        checks.check_df([1, 2, 3])
    except TypeError:
        pass
    else:
        assert False, "Expected TypeError for non-DataFrame"

    try:
        checks.check_df(pd.DataFrame())
    except ValueError:
        pass
    else:
        assert False, "Expected ValueError for empty DataFrame"

    try:
        checks.check_df(pd.DataFrame({"a": [None, None]}))
    except ValueError:
        pass
    else:
        assert False, "Expected ValueError for DataFrame all NaNs"


def test_check_gdf():
    """Test that check_gdf validates input as non-empty GeoDataFrame with valid geometries."""
    gdf = gpd.GeoDataFrame({'geometry': [Point(0, 0)]})
    checks.check_gdf(gdf)

    try:
        checks.check_gdf(pd.DataFrame())
    except TypeError:
        pass
    else:
        assert False, "Expected TypeError for non-GeoDataFrame"

    try:
        checks.check_gdf(gpd.GeoDataFrame())
    except ValueError:
        pass
    else:
        assert False, "Expected ValueError for empty GeoDataFrame"

    empty_geom = gpd.GeoDataFrame({'geometry': [None, None]})
    try:
        checks.check_gdf(empty_geom)
    except ValueError:
        pass
    else:
        assert False, "Expected ValueError for GeoDataFrame with empty geometries"


def test_check_member():
    """Test that check_member confirms presence of a member in a collection."""
    checks.check_member('a', ['a', 'b', 'c'])

    try:
        checks.check_member('d', ['a', 'b', 'c'])
    except ValueError:
        pass
    else:
        assert False, "Expected ValueError for invalid member"
