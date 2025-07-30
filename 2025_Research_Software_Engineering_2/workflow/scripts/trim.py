"""
This script trims rows from the beginning and end of a CSV file and saves the result.

It reads a CSV file into a pandas DataFrame, removes a specified number of rows from
the top and bottom, and writes the trimmed DataFrame to a new file.

Usage:
    python trim.py <input_path> <output_path> <beginning> <ending>

Arguments:
    input_path (str or Path):   Path to the input CSV file.
    output_path (str or Path):  Path where the trimmed CSV will be saved.
    beginning (int or str):     Number of rows to trim from the beginning (must be >= 0).
    ending (int or str):        Number of rows to trim from the end (must be >= 0).
"""
import os
import sys
import utils
import checks
import logs


def trim(input_path, output_path, beginning, ending):
    """
    Trim rows from the beginning and end of a DataFrame loaded from a CSV file.

    The function reads the data, trims the specified number of rows from both
    the top and bottom, and saves the result to a CSV file.

    Args:
        input_path (str): Path to the input CSV file.
        output_path (str): Path where the trimmed CSV file will be saved.
        beginning (int or str): Number of rows to remove from the start.
        ending (int or str): Number of rows to remove from the end.

    Returns:
        None: The trimmed data is written to the file specified by `output_path`.
    """
    logs.log_processing(os.path.basename(__file__))
    logs.log_parameter("beginning", str(beginning))
    logs.log_parameter("ending", str(ending))
    checks.check_path(input_path)
    checks.check_dir(output_path)
    checks.check_empty(beginning)
    checks.check_empty(ending)

    beginning = int(beginning)
    ending = int(ending)
    data = utils.read_df(input_path, ",", 0, 0)
    data = data.iloc[beginning:len(data)-ending]

    utils.save_df(data, output_path)
    logs.log_processed(os.path.basename(__file__))


if __name__ == "__main__":
    checks.check_args(5, __doc__)
    trim(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
