import geopandas as gpd
import pandas as pd


def load_gpkg_to_dataframe(gpkg_path, layer_name=None):
    """
    Load attribute data from a GeoPackage into a pandas DataFrame.

    Parameters:
    - gpkg_path (str): Path to the GeoPackage file (.gpkg).
    - layer_name (str, optional): Name of the layer in the GeoPackage. 
      If None, the first layer will be used.

    Returns:
    - pd.DataFrame: DataFrame containing attribute data (geometry excluded).
    """
    # Load the GeoPackage layer into a GeoDataFrame
    gdf = gpd.read_file(gpkg_path, layer=layer_name)

    # Drop the geometry column if it exists
    if 'geometry' in gdf.columns:
        gdf = gdf.drop(columns='geometry')

    # Convert to pandas DataFrame
    df = pd.DataFrame(gdf)

    return df
