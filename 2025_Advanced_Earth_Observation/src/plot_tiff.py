import os
import sys
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import matplotlib.patches as mpatches
import geopandas as gpd
import rasterio
from rasterio.plot import show
import pandas as pd


def plot_tiff(input_path, output_path, meta, title, color="#00000"):
    class_names = meta['class_name'].tolist()
    class_ids = meta['class_id'].tolist()
    colors = meta['class_color'].tolist()

    cmap = mcolors.ListedColormap(colors)
    norm = mcolors.BoundaryNorm(class_ids + [max(class_ids)+1], cmap.N)
    legend_patches = [mpatches.Patch(
        color=colors[i], label=class_names[i]) for i in range(len(class_names))]

    raster = rasterio.open(input_path)

    fig, ax = plt.subplots()
    fig.patch.set_facecolor(color)
    show(raster, ax=ax, cmap=cmap, norm=norm)
    ax.get_xaxis().get_major_formatter().set_useOffset(False)
    ax.get_yaxis().get_major_formatter().set_useOffset(False)
    ax.ticklabel_format(style='plain', axis='both', useOffset=False)

    ax.set_xlabel("Longitude", color="white")
    ax.set_ylabel("Latitude", color="white")
    for label in (ax.get_xticklabels() + ax.get_yticklabels()):
        label.set_color("white")
    ax.set_title(title, color="white")
    ax.tick_params(color="white")
    ax.set_facecolor(color)
    for spine in ax.spines.values():
        spine.set_color("white")
    patches = [mpatches.Patch(color=colors[i], label=class_names[i])
               for i in range(len(class_names))]
    ax.legend(handles=patches, loc="upper right",
              fontsize='small', frameon=True, facecolor=color,  # legend background
              edgecolor=color,    # legend border color
              labelcolor="white", framealpha=1.0)
    plt.savefig(output_path)


if __name__ == "__main__":
    plot_tiff(sys.argv[1], sys.argv[2])
