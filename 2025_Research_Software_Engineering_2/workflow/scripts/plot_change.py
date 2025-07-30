'''
This script visualizes changes in energy production or sunshine duration,
either monthly or yearly, using line plots based on a CSV input file.

Depending on the structure of the input data, the script creates:
- A monthly line plot for a selected year if the CSV contains one row per year
  and one column per month.
- A yearly line plot if the CSV contains only two columns: year and value.

Usage:
    python plot_change.py <input_path> <output_path> <title> <year_filter>

Arguments:
    input_path (Path or str):    Path to the input CSV file containing energy or sunshine data.
    output_path (Path or str):   File path where the generated plot (e.g., PNG) will be saved.
    title (str):                 Title of the plot.
    year_filter (str or int):    Year to select from the dataset for monthly plots.
                                 Required if the input contains monthly values.

'''
import os
import sys
import matplotlib.pyplot as plt
import utils
import checks
import logs


def plot_change(input_path, output_path, title, year_filter=None):
    """
    Generate and save a line plot showing energy or sunshine changes over time.

    If the input contains multiple columns (i.e., monthly values), this function will
    extract the row corresponding to `year_filter` and plot the monthly trend.
    Otherwise, it assumes the data is already in a year-to-value format.

    Args:
        input_path (Path or str):   Path to the input CSV file.
        output_path (Path or str):  Path to save the generated plot image.
        title (str):                Title of the plot.
        year_filter (str or int, optional): Year to filter for when plotting monthly data.

    Returns:
        None: The generated diagram is saved as an image file at output_path.
    """
    logs.log_processing(os.path.basename(__file__))
    checks.check_path(input_path)
    checks.check_dir(output_path)
    checks.check_empty(title)

    data = utils.read_df(input_path, ",", 0, None)

    if data.shape[1] > 2:
        x_label = "Month"
        y_label = "Energy [kWh]"

        data = data.set_index("year")

        x_ticks = data.columns
        x_values = range(len(data.columns))
        y_value = data.transpose()[int(year_filter)]
    else:
        x_label = data.columns[0]
        y_label = data.columns[-1]
        x_ticks = data.iloc[:, 0].values.astype(str)
        x_values = range(len(x_ticks))
        y_value = data.iloc[:, 1].values

    figure, ax = plt.subplots()
    ax.set_title(title)
    ax.set_xlabel(x_label)
    ax.set_ylabel(y_label)
    ax.set_xticks(range(len(x_ticks)))
    ax.set_xticklabels(x_ticks, rotation=45)
    ax.plot(x_values, y_value, 'o:')
    figure.tight_layout()
    plt.savefig(output_path)
    logs.log_processed(os.path.basename(__file__))


if __name__ == "__main__":
    checks.check_args(5, __doc__)
    plot_change(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
