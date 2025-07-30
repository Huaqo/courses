import sys
import matplotlib.pyplot as plt
from rasterio.plot import show
import rasterio


def plot_tiff_2(input_path, output_path, title, background_color="#000000"):
    # Open the raster
    raster = rasterio.open(input_path)

    # Use a built-in colormap (e.g., "rainbow")
    cmap = plt.get_cmap("rainbow")

    # Plot
    fig, ax = plt.subplots()
    fig.patch.set_facecolor(background_color)
    show(raster, ax=ax, cmap=cmap)
    ax.get_xaxis().get_major_formatter().set_useOffset(False)
    ax.get_yaxis().get_major_formatter().set_useOffset(False)
    ax.ticklabel_format(style='plain', axis='both', useOffset=False)

    # Style axes and title
    ax.set_xlabel("Longitude", color="white")
    ax.set_ylabel("Latitude", color="white")
    for label in (ax.get_xticklabels() + ax.get_yticklabels()):
        label.set_color("white")
    ax.set_title(title, color="white")
    ax.tick_params(color="white")
    ax.set_facecolor(background_color)
    for spine in ax.spines.values():
        spine.set_color("white")

    # Save figure
    plt.savefig(output_path)


if __name__ == "__main__":
    input_path = sys.argv[1]
    output_path = sys.argv[2]
    title = sys.argv[3] if len(sys.argv) > 3 else "Raster Plot"
    plot_tiff_2(input_path, output_path, title)
