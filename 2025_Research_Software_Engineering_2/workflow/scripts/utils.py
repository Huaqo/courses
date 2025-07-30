"""
Utility functions for solalytics.
"""
import requests
import pandas as pd
import geopandas as gpd
from bs4 import BeautifulSoup
import checks
import logs


def is_number(s):
    """
    Checks if given string is a number.

    Arguemtns:
        s (str): String to be checked.

    Returns:
        Bool: if string is number or not.

    """
    try:
        float(s)
        return True
    except ValueError:
        return False


def parse_number(content):
    """
    Parses number from file content.

    Arguments:
        content (str): file content to be parsed.

    Returns:
        float/int: parsed number.
    """
    content = content.strip()
    if is_number(content):
        return float(content) if '.' in content else int(content)
    raise ValueError("The file does not contain a valid number.")


def request_response(url):
    """
    Request a reponse from a URL.

    Arguments:
        url (str): URL to be requested.

    Returns:
        response (str): response from the URL.
    """
    checks.check_empty(url)
    response = requests.get(url, timeout=2.5)
    checks.check_empty(response)
    return response


def parse_html(response):
    """
    Parses HTML from a web response.

    Arguments:
        response (str): Response to be parsed.

    Returns:
        html: parsed HTML.
    """
    html = BeautifulSoup(response.text, 'html.parser')
    checks.check_empty(html)
    return html


def read_file(path):
    """
    Read a file and return its contents.

    Args:
        path (str): Path to the input file.

    Returns:
        str: The loaded content.

    Raises:
        FileNotFoundError: If the file does not exist.
        OSError: If the file cannot be opened or read.
    """
    checks.check_path(path)
    try:
        with open(path, 'r', encoding="utf-8") as file:
            content = file.read().strip()
            checks.check_empty(content)
            logs.log_read(path)
            return content
    except OSError:
        logs.log_read_error(path)
        raise


def save_file(file, path):
    """
    Saves fiven file as file to the specified path.

    Args:
        file: content of the file
        path: The target file path where the file will be written.
    """
    checks.check_empty(file)
    checks.check_dir(path)
    try:
        with open(path, 'w', encoding="utf-8") as f:
            f.write(file)
            logs.log_saved(path)
    except OSError:
        logs.log_saved_error(path)
        raise


def read_df(path, seperator, header_line, icol):
    """
    Read a csv file and return a DataFrame.

    Args:
        path (str): Path to the input file.
        seperator (str): csv seperator

    Returns:
        dataframe: The loaded content.

    Raises:
        FileNotFoundError: If the file does not exist.
        ValueError: If dataframe is empty
        OSError: If the file cannot be opened or read.
    """
    checks.check_path(path)
    try:
        data = pd.read_csv(path, sep=seperator,
                           header=header_line, index_col=icol)
        checks.check_df(data)
        logs.log_read(path)
        return data
    except OSError:
        logs.log_read_error(path)
        raise


def save_df(df, path, index_input=True):
    """
    Saves the given DataFrame as a CSV file to the specified path.

    Args:
        df : The DataFrame to save.
        path : The target file path where the CSV will be written.

    Raises:
        FileNotFoundError: If the target directory does not exist.
        Exception: If saving the file fails.
    """
    checks.check_df(df)
    checks.check_dir(path)
    try:
        df.to_csv(path, index=index_input)
        logs.log_saved(path)
    except OSError:
        logs.log_saved_error(path)


def read_gdf(path):
    """
    Read a geopackage and return a GeoDataFrame.

    Args:
        path (str): Path to the input file.

    Returns:
        geodataframe: The loaded content.

    Raises:
        FileNotFoundError: If the file does not exist.
        ValueError: If dataframe is empty
        OSError: If the file cannot be opened or read.
    """
    checks.check_path(path)

    try:
        data = gpd.read_file(path)
        checks.check_gdf(data)
        logs.log_read(path)
        return data
    except OSError:
        logs.log_read_error(path)
        raise


def save_gdf(gdf, path):
    """
    Saves the given GeoDataFrame as a GeoPackage to the specified path.

    Arguments:
        gdf: The GeoDataFrame to save.
        path: The target file path where the .gpkg will be written.

    Raises:
        FileNotFoundError: If the target directory does not exist.
        Exception: If saving the file fails.
    """
    checks.check_gdf(gdf)
    checks.check_dir(path)
    try:
        gdf.to_file(path, driver='gpkg')
        logs.log_saved(path)
    except OSError:
        logs.log_saved_error(path)
