"""
Calculate and compare yearly energy sums from actual photovoltaic and theoretical solar datasets.

This script reads two CSV datasets containing monthly energy values per year — one representing
actual photovoltaic energy measurements, the other representing theoretical solar radiation
estimates. It sums the monthly values per year, and merges the results into a single output file
for comparison or further analysis.

Usage:
    python calculate_difference.py <actual_energy_path> <theoretical_energy_path>
                                 <output_path>

Arguments:
    actual_energy_path (str or Path):         path to CSV file with actual photovoltaic energy data.
    theoretical_energy_path (str or Path):    path to CSV file with theoretical solar radiation
                                              data.
    output_path (str or Path):                destination path for the merged yearly sums output
                                              CSV.
"""

import os
import sys
import pandas as pd
import utils
import checks
import logs


def calc_energy_difference(df_actual_path, df_theoretical_path, output_path):
    """
    Calculate the absolute yearly energy difference between actual and theoretical datasets.

    Reads two CSV files with yearly energy data, computes the absolute difference
    in energy values for each common year, and saves the result as a CSV.

    Args:
        df_actual_path (str or Path):       Path to the CSV file with actual photovoltaic energy
                                            data.
        df_theoretical_path (str or Path):  Path to the CSV file with theoretical solar radiation
                                            data.
        output_path (str or Path):          Path where the output CSV with yearly energy differences
                                            will be saved.

    Returns:
        None: The result is saved to `output_path`.
    """
    logs.log_processing(os.path.basename(__file__))

    checks.check_path(df_actual_path)
    checks.check_path(df_theoretical_path)
    checks.check_dir(output_path)

    df_actual = utils.read_df(df_actual_path, ",", 0, None)
    df_theoretical = utils.read_df(df_theoretical_path, ",", 0, None)

    diff_difference = abs(
        df_actual[df_actual.columns[1]] - df_theoretical[df_theoretical.columns[1]])
    df_diff = pd.DataFrame({
        'year': df_actual['year'],
        'Energy Difference [kWh]': diff_difference})
    utils.save_df(df_diff, output_path, False)
    logs.log_processed(os.path.basename(__file__))


if __name__ == "__main__":
    checks.check_args(4, __doc__)
    calc_energy_difference(sys.argv[1], sys.argv[2], sys.argv[3])
