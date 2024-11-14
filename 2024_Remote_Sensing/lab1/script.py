import geopandas as gpd
import rasterio
from rasterio.mask import mask
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.ticker import ScalarFormatter

# Read the original shapefile
gdf = gpd.read_file('continent_overlay/Continent_Outlines.shp')

# Path to the raster file
raster_path = 'gtopo_world_dem_6m.tif'

# Open the raster file
with rasterio.open(raster_path) as src:
    plt.figure(figsize=(14, 8))  # Create a larger figure for better visualization

    # Loop through each unique continent
    for continent in gdf['CONTINENT'].unique():
        # Filter GeoDataFrame for the current continent
        gdf_continent = gdf[gdf['CONTINENT'] == continent]
        
        # Clip the raster with the geometry of the current continent
        out_image, out_transform = mask(src, gdf_continent.geometry, crop=True)
        
        # Flatten the array and remove masked values
        data = out_image[0].flatten()  # Assuming a single-band raster
        data = data[(data != src.nodata) & (data >= 0) & (data <= 7000)]  # Remove nodata values and filter the range

        # Calculate histogram data (bin counts)
        counts, bin_edges = np.histogram(data, bins=50, range=(0, 7000))

        # Plot the line for this continent
        plt.plot(bin_edges[:-1], counts, label=continent, linewidth=1.5)

    # Add x-axis and y-axis limits, legend, title, and labels
    plt.xlim(0, 7000)
    plt.ylim(0, 40000)
    plt.gca().yaxis.set_major_formatter(ScalarFormatter(useOffset=False))  # Ensure y-axis shows whole numbers
    plt.ticklabel_format(style='plain', axis='y')  # Disable scientific notation
    plt.legend(loc='upper right')
    plt.xlabel('Elevation (m)')
    plt.ylabel('Count')

    # Save the plot to a file
    plt.savefig('plot1.png')

    print('Line plot saved as "plot1.png"')
