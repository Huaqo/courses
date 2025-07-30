"""
This script reads a tabular CSV dataset, sums the values across all columns for each row,
and writes the resulting single-column DataFrame to an output file.

Usage:
    python collapse_columns.py <input_path> <output_path> <column_name>

Arguments:
    input_path (str or Path):  Path to the input CSV file containing the original tabular data.
    output_path (str or Path): Path where the collapsed output CSV file will be saved.
    column_name (str):         Name of the column in the output file representing the summed values.
"""
import os
import sys
import utils
import checks
import logs


def collapse_columns(input_path, output_path, column_name):
    """
    Reads a tabular dataset and collapses each row into a single value by summing across columns.
    The result is written as a single-column DataFrame to the output path.

    Args:
        input_path (str or Path):   Path to the input CSV file.
        output_path (str or Path):  Path where the output CSV file will be saved.
        column_name (str):          Name of the resulting summed column.

    Returns:
        None: The resulting summed dataframe is saved to `output_path`
    """
    logs.log_processing(os.path.basename(__file__))
    logs.log_parameter("column_name", str(column_name))
    checks.check_path(input_path)
    checks.check_dir(output_path)

    data = utils.read_df(input_path, ",", 0, 0)
    data = data.sum(axis=1).to_frame(name=column_name)
    utils.save_df(data, output_path)
    logs.log_processed(os.path.basename(__file__))


if __name__ == "__main__":
    checks.check_args(4, __doc__)
    collapse_columns(sys.argv[1], sys.argv[2], sys.argv[3])
