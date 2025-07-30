import os
import sys
import matplotlib.pyplot as plt
import rasterio
from rasterio.plot import show


def plot_tiff_rgb(input_path, output_path):
    with rasterio.open(input_path) as src:
        rgb = src.read([1, 2, 3])

        # Plot
        fig, ax = plt.subplots()
        show(rgb, transform=src.transform, ax=ax)
        ax.set_xlabel("Longitude")
        ax.set_ylabel("Latitude")

        # Save the figure
        plt.savefig(output_path, dpi=300, bbox_inches='tight')


if __name__ == "__main__":
    plot_tiff_rgb(sys.argv[1], sys.argv[2])
