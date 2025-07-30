"""
Basic input validation checks.

Functions to check for :
- non-empty variables,
- existing file or directory paths
- correct command-line argument count
- two CRS's if they are equal
- dataframe valid and not empty
- if GeoDataFrame is valid and not empty
- if variable is member of a list
"""

import os
import sys
from pathlib import Path
import pandas as pd
import geopandas as gpd


def check_empty(variable):
    """
    Checks if variable is not empty.

    Arguments:
        variable: variable to check.

    Returns:
        None

    Raises:
        ValueError: If the variable is empty.
    """
    if not variable:
        raise ValueError("Variable is empty")


def check_path(path):
    """
    Checks if path exists.

    Arguments:
        path (str): path to check.

    Returns:
        None

    Raises:
        FileNotFoundError: If the path does not exist.
    """
    if not os.path.exists(path):
        raise FileNotFoundError(f"Invalid path: {path}")


def check_dir(path):
    """
    Checks if directory exists.

    Arguments:
        path (str): path to check.

    Returns:
        None

    Raises:
        FileNotFoundError: If the directory's parent path does not exist.
    """
    if not Path(path).parent.exists():
        raise FileNotFoundError(f"Invalid directory path: {path}")


def check_args(num_arg, output):
    """
    Checks sys arguments length against expected.

    Args:
        num_arg (int): expected number of arguments.
        output (str): string to be printed in case of check failure.

    Returns:
        None

    Raises:
        RuntimeError: If the number of arguments does not match `num_arg`.
    """
    if len(sys.argv) != num_arg:
        raise RuntimeError(output)


def check_crs(crs1, crs2):
    """
    Checks two CRS's if they are equal.

    Arguments:
        crs1: first CRS.
        crs2: second CRS.

    Returns:
        None

    Raises:
        ValueError: If CRS's are not equal.
    """
    if crs1 != crs2:
        raise ValueError("CRS missmatch.")


def check_df(df):
    """
    Checks if DataFrame is valid and not empty.

    Arguments:
        df: DataFrame to check.

    Returns:
        None

    Raises:
        TypeError: If not a DataFrame
        ValueError: If DataFrame is empty
        ValueError: If all values in the DataFrame are NaN
    """
    if not isinstance(df, pd.DataFrame):
        raise TypeError("Not a DataFrame.")

    if df.empty:
        raise ValueError("DataFrame is empty.")

    if df.isna().all().all():
        raise ValueError("DataFrame contains only NaN values.")


def check_gdf(gdf):
    """
    Checks if GeoDataFrame is valid and not empty.

    Arguments:
        gdf: GeoDataFrame to check.

    Returns:
        None

    Raises:
        TypeError: if not an GeoDataFrame
        ValueError: If GeoDataFrame is empty
        ValueError: If includes empty geometries

    """
    if not isinstance(gdf, gpd.GeoDataFrame):
        raise TypeError("Not a GeoDataFrame.")

    if gdf.empty:
        raise ValueError("GeoDataFrame is empty.")

    if gdf.geometry.isna().all():
        raise ValueError("GeoDataFrame includes empty geometries.")


def check_member(variable, members):
    """
    Check if variable is member of a list.

    Arguments:
        variable: to check
        members (list): to check against.

    Returns:
        None

    Raises:
        ValueError: If variable is not member of allowed varibales.

    """
    if variable not in members:
        raise ValueError(f"Invalid value: {
                         variable}. Must be one of: {members}")
