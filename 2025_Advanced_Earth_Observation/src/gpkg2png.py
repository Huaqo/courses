import os
import sys
import matplotlib.pyplot as plt
import geopandas as gpd
import rasterio
from rasterio.plot import show as rioshow


def gpkg2png(input_path, base_path, output_path, title, color):
    # Load vector data
    data = gpd.read_file(input_path)

    # Load raster base map
    with rasterio.open(base_path) as src:
        base_crs = src.crs
        raster_data = src.read()

    # Reproject vector data if CRS differs
    if data.crs != base_crs:
        data = data.to_crs(base_crs)

    # Set up figure and axes
    fig, ax = plt.subplots()
    fig.patch.set_facecolor(color)
    ax.set_xlabel("Longitude", color="white")
    ax.set_ylabel("Latitude", color="white")

    ax.ticklabel_format(style='plain', axis='both', useOffset=False)
    # Plot raster background
    rioshow(raster_data, transform=src.transform, ax=ax)

    # Plot vector data
    data.plot(
        ax=ax,
        facecolor="none",           # Transparent fill
        edgecolor="white",          # White border for circles
        linewidth=1,                # Thickness of circle edges
        alpha=0.7,                  # Transparency for the edges
        marker='o',                 # Ensure point geometries are circles
        markersize=100              # Adjust size as needed
    )
    # Style adjustments
    for label in (ax.get_xticklabels() + ax.get_yticklabels()):
        label.set_color("white")

    ax.set_title(title, color="white")
    ax.tick_params(color="white")
    ax.set_facecolor(color)
    for spine in ax.spines.values():
        spine.set_color("white")

    plt.savefig(output_path, bbox_inches='tight',
                facecolor=fig.get_facecolor())


if __name__ == "__main__":
    gpkg2png(sys.argv[1], sys.argv[2], sys.argv[3])
