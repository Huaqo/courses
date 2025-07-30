"""
Unit tests for the calculate_difference.py module, which verifies the correctness
of the energy difference calculation.
"""

from unittest import mock
import pandas as pd
from calculate_difference import calc_energy_difference


@mock.patch("calculate_difference.logs.log_processed")
@mock.patch("calculate_difference.logs.log_processing")
@mock.patch("calculate_difference.checks.check_dir")
@mock.patch("calculate_difference.checks.check_path")
@mock.patch("calculate_difference.utils.save_df")
@mock.patch("calculate_difference.utils.read_df")
def test_calc_energy_difference(mock_read_df, mock_save_df,
                                  _mock_check_path, _mock_check_dir,
                                  _mock_log_processing, _mock_log_processed):
    """
    Test that calc_difference_difference computes the correct energy difference per
    year and saves the expected DataFrame.
    """
    df_actual = pd.DataFrame({
        'year': [2018, 2019, 2020],
        'Summe': [100, 200, 300]
    })
    df_theoretical = pd.DataFrame({
        'year': [2018, 2019, 2020],
        'Summe': [90, 210, 310]
    })

    mock_read_df.side_effect = [df_actual, df_theoretical]
    calc_energy_difference("actual.csv", "theoretical.csv", "output.csv")

    expected_diff = abs(df_actual['Summe'] - df_theoretical['Summe'])
    expected_df = pd.DataFrame({
        'year': df_actual["year"],
        'Energy Difference [kWh]': expected_diff
    })

    result_df = mock_save_df.call_args[0][0]
     # adjust types, because "2018" =/= 2018
    expected_df["year"] = expected_df["year"].astype(int)
    result_df["year"] = result_df["year"].astype(int)

    pd.testing.assert_frame_equal(
        result_df.sort_values(by="year").reset_index(drop=True),
        expected_df.sort_values(by="year").reset_index(drop=True)
    )


@mock.patch("calculate_difference.logs.log_processed")
@mock.patch("calculate_difference.logs.log_processing")
@mock.patch("calculate_difference.checks.check_dir")
@mock.patch("calculate_difference.checks.check_path")
@mock.patch("calculate_difference.utils.save_df")
@mock.patch("calculate_difference.utils.read_df")
def test_calc_energy_difference_dimensions(mock_read_df, mock_save_df,
                                             _mock_check_path, _mock_check_dir,
                                             _mock_log_processing, _mock_log_processed):
    """
    Test that the resulting DataFrame has the expected shape: same row count as input
    and two columns ('year' and 'Energy Difference [kWh]').
    """
    df_actual = pd.DataFrame({
        'year': [2018, 2019, 2020],
        'Summe': [100, 200, 300]
    })
    df_theoretical = pd.DataFrame({
        'year': [2018, 2019, 2020],
        'Summe': [90, 210, 310]
    })

    mock_read_df.side_effect = [df_actual, df_theoretical]
    calc_energy_difference("actual.csv", "theoretical.csv", "output.csv")
    result_df = mock_save_df.call_args[0][0]

    # checks whether the number of rows is the same
    assert len(result_df) == len(df_actual)

    # checks exactly 2 columns ("year", "energy difference")
    assert result_df.shape[1] == 2
