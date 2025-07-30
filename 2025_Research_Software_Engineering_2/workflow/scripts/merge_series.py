"""
This script combines monthly sunshine duration data from twelve CSV files
in a given directory by extracting the German average values and merging
them into a single DataFrame. The combined data is then saved as a CSV file.

Original datasets from:
https://opendata.dwd.de/climate_environment/CDC/regional_averages_DE/monthly/sunshine_duration/

Usage:
    python merge_series.py <input_directory> <output_path>

Arguments:
    input_directory (Path or str):  Directory containing the twelve monthly CSV input files.
    output_path (Path or str):      Path where the combined CSV output file will be saved.
"""

import os
import sys
import pandas as pd
import utils
import checks
import logs


def merge_series(input_directory, output_path):
    """
    Extracts the German average sunshine duration series from twelve monthly CSV files
    in the specified directory and combines them into a single pandas DataFrame.
    The DataFrame columns represent months, and rows represent years.

    Args:
        input_directory (Path or str):  Directory containing the input CSV files.
        save_path (Path or str):        File path to save the combined CSV output.

    Returns:
        None: The resulting combined dataframe is saved to `output_path`
    """
    logs.log_processing(os.path.basename(__file__))
    checks.check_path(input_directory)
    checks.check_dir(output_path)

    files = os.listdir(input_directory)
    checks.check_empty(files)

    txt_files = sorted([f for f in files if f.lower().endswith('.txt')])

    series_list = []
    month_list = ["January", "February", "March", "April", "May", "June",
                  "July", "August", "September", "October", "November", "December"]

    for file, month in zip(txt_files, month_list):
        data = utils.read_df(input_directory+"/"+file, ";", 1, 0)
        data = data["Deutschland"]
        data.name = month
        series_list.append(data)
    df = pd.concat(series_list, axis=1)
    df = df[df.index != 2025]

    utils.save_df(df, output_path)
    logs.log_processed(os.path.basename(__file__))


if __name__ == "__main__":
    checks.check_args(3, __doc__)
    merge_series(sys.argv[1], sys.argv[2])
