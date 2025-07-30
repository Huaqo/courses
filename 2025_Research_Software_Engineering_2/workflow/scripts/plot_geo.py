"""
This script reads geographic data files, creates a map visualization by
plotting the data on top of a base map, and saves the resulting map as
an image file.

Usage:
    python plot_geo.py <input_path> <base_path> <output_path> <title>

Arguments:
    input_path (str or Path):   Path to the geographic data file to be plotted.
    base_path (str or Path):    Path to the base map geographic data file.
    output_path (str or Path):  Path where the generated map image will be saved.
    title (str):                Title for the map.
"""

import os
import sys
import matplotlib.pyplot as plt
import utils
import checks
import logs


def plot_geo(input_path, base_path, output_path, title):
    """
    Generate a map image by plotting geographic data over a base map.

    Arguments:
        input_path (str): Path to the geographic data file to be plotted.
        base_path (str): Path to the base map geographic data file.
        output_path (str): Path where the generated map image will be saved.
        title (str): Title of the map for the plot.

      Returns:
        None: The generated map is saved as an image file at output_path.
    """
    logs.log_processing(os.path.basename(__file__))
    logs.log_parameter("title", str(title))
    checks.check_path(input_path)
    checks.check_path(base_path)
    checks.check_dir(output_path)
    checks.check_empty(title)

    data = utils.read_gdf(input_path)
    base = utils.read_gdf(base_path)

    _, ax = plt.subplots()
    ax.set_title(title)
    ax.set_xlabel("Longitude")
    ax.set_ylabel("Latitude")
    base.plot(ax=ax, color="white", edgecolor="black")
    data.plot(ax=ax, color="blue", edgecolor="blue")

    plt.savefig(output_path)
    logs.log_saved(output_path)
    logs.log_processed(os.path.basename(__file__))


if __name__ == "__main__":
    checks.check_args(5, __doc__)
    plot_geo(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
