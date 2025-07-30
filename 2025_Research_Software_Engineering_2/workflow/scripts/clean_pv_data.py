"""
Process and clean photovoltaic dataset from Destatis.

This script reads a CSV dataset (exported from the Destatis web portal), removes
unnecessary table structures caused by web-to-CSV conversion, and saves a cleaned version.
It also allows extracting a subset of the data, e.g. "Electricity feed-in systems",
"Net nominal capacity", or "Electricity feed-in".

Original dataset source:
https://www-genesis.destatis.de/datenbank/online/statistic/43312/table/43312-0001

Usage:
    python clean_pv_data.py <dataset_path> <save_path> <extracted_type>

Arguments:
    dataset_path (str or Path): Path to the raw CSV dataset file.
    save_path (str or Path):    Path where the cleaned CSV will be saved.
    extracted_type (str):       Type of data to extract (e.g., "Electricity feed-in").
"""
import os
import sys
import pandas as pd
import utils
import checks
import logs



def clean_pv_data(input_path, output_path, extracted_type):
    """
    Clean and preprocess the photovoltaic dataset from Destatis.

    This function selects relevant columns, renames them for clarity,
    defines categorical ordering for months and data types, sorts the data,
    and extracts the specified subset. The result is saved as a pivot table CSV.

    Args:
        input_path (str or Path):   Path to the raw input CSV file.
        output_path (str or Path):  Path to save the cleaned and extracted CSV.
        extracted_type (str):       The category of data to extract (e.g., "Electricity feed-in").

    Returns:
        None: The processed DataFrame is saved to `output_path`.
    """

    logs.log_processing(os.path.basename(__file__))

    checks.check_path(input_path)
    checks.check_dir(output_path)
    checks.check_empty(extracted_type)

    df = utils.read_df(input_path, seperator=";", header_line=0, icol=None)

    df_relevant = df[["time", "1_variable_attribute_label",
                      "value", "value_variable_label"]]
    df_cleaned = df_relevant.rename(columns={
        'time': 'year',
        '1_variable_attribute_label': 'month',
        'value_variable_label': 'type'
    })
    monthly_order = ["January", "February", "March", "April", "May", "June",
                     "July", "August", "September", "October", "November", "December"]
    # Units:     [number, MW, Mwh]
    type_order = ["Electricity feed-in systems",
                  "Net nominal capacity", "Electricity feed-in"]

    df_cleaned['month'] = pd.Categorical(
        df_cleaned['month'], categories=monthly_order, ordered=True)
    df_cleaned['type'] = pd.Categorical(
        df_cleaned['type'], categories=type_order, ordered=True)
    df_cleaned = df_cleaned.sort_values(
        by=['year', 'month', 'type'], ascending=True)

    extracted_df = df_cleaned[df_cleaned["type"] == extracted_type]
    pivot_df = extracted_df.pivot(
        index="year", columns="month", values="value")

    checks.check_df(pivot_df)
    utils.save_df(pivot_df, output_path)
    logs.log_processed(os.path.basename(__file__))


if __name__ == "__main__":
    checks.check_args(4, __doc__)
    clean_pv_data(sys.argv[1], sys.argv[2], sys.argv[3])
