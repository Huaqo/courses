"""Unit tests for utils.py"""

from unittest.mock import Mock
import pytest
import pandas as pd
import geopandas as gpd

import utils


def test_is_number():
    """Test if strings are correctly identified as numbers or not."""
    assert utils.is_number("42") is True
    assert utils.is_number("3.14") is True
    assert utils.is_number("abc") is False
    assert utils.is_number("") is False


def test_parse_number():
    """Test parsing numeric strings to int or float and raising errors for invalid input."""
    assert utils.parse_number("42") == 42
    assert utils.parse_number("3.14") == 3.14
    with pytest.raises(ValueError):
        utils.parse_number("not a number")


def test_request_response():
    """Test HTTP GET request and check if response has expected structure."""
    response = utils.request_response("https://httpbin.org/get")
    assert response.status_code == 200
    assert "url" in response.json()


def test_parse_html():
    """Test parsing HTML content and extracting elements."""
    mock_response = Mock()
    mock_response.text = "<html><body><p>Hello</p></body></html>"
    result = utils.parse_html(mock_response)
    assert result.p.text == "Hello"


def test_read_file(local_tmp_path):
    """Test reading content from a file."""
    test_path = local_tmp_path / "test.txt"
    test_path.write_text("test content")
    content = utils.read_file(test_path)
    assert content == "test content"


def test_save_file(local_tmp_path):
    """Test saving content to a file."""
    test_path = local_tmp_path / "output.txt"
    utils.save_file("saved content", test_path)
    assert test_path.read_text() == "saved content"


def test_read_df(local_tmp_path):
    """Test reading a CSV file into a pandas DataFrame."""
    csv_path = local_tmp_path / "test.csv"
    csv_path.write_text("a,b\n1,2\n3,4")
    df = utils.read_df(csv_path, seperator=",", header_line=0, icol=None)
    assert not df.empty


def test_save_df(local_tmp_path):
    """Test saving a pandas DataFrame to a CSV file."""
    df = pd.DataFrame({"x": [1, 2], "y": [3, 4]})
    path = local_tmp_path / "output.csv"
    utils.save_df(df, path)
    loaded = pd.read_csv(path, index_col=0)
    pd.testing.assert_frame_equal(df, loaded)


def test_read_gdf(local_tmp_path):
    """Test reading a GeoDataFrame from a GeoPackage file."""
    gdf = gpd.GeoDataFrame(
        {'col': [1]}, geometry=gpd.points_from_xy([0], [0]), crs="EPSG:4326")
    path = local_tmp_path / "test.gpkg"
    gdf.to_file(path, driver="GPKG")

    result = utils.read_gdf(path)
    assert isinstance(result, gpd.GeoDataFrame)
    assert result.equals(gdf)


def test_save_gdf(local_tmp_path):
    """Test saving a GeoDataFrame to a GeoPackage file."""
    gdf = gpd.GeoDataFrame(
        {'col': [1]}, geometry=gpd.points_from_xy([0], [0]), crs="EPSG:4326")
    path = local_tmp_path / "output.gpkg"
    utils.save_gdf(gdf, path)
    loaded = gpd.read_file(path)
    assert isinstance(loaded, gpd.GeoDataFrame)
    assert loaded.equals(gdf)
