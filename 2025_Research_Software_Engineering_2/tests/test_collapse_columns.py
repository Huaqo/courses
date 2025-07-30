"""
Unit tests for the collapse_columns function, which merges multiple columns
by summing their values.
"""
from unittest.mock import patch
import pandas as pd
from collapse_columns import collapse_columns


@patch("utils.save_df")
@patch("utils.read_df")
@patch("checks.check_dir")
@patch("checks.check_path")
def test_sum_values_correctly(_mock_check_path, _mock_check_dir,
                              mock_read_df, mock_save_df):
    """
    Test that collapse_columns sums values across all columns and stores the
    result in the specified column.
    """
    input_df = pd.DataFrame({"A": [1, 2, 3], "B": [4, 5, 6]})
    column_name = "sum"

    expected_df = pd.DataFrame({column_name: [5, 7, 9]})
    mock_read_df.return_value = input_df
    collapse_columns("in.csv", "out.csv", column_name)
    result_df = mock_save_df.call_args[0][0]

    pd.testing.assert_frame_equal(result_df, expected_df)


@patch("utils.save_df")
@patch("utils.read_df")
@patch("checks.check_dir")
@patch("checks.check_path")
def test_output_dimension(_mock_check_path,
                          _mock_check_dir, mock_read_df, mock_save_df):
    """
    Test that the output DataFrame has one column after merging and retains
    the original number of rows.
    """
    input_df = pd.DataFrame({
        "X": [1, 2],
        "Y": [3, 4]
    })
    column_name = "sum"

    mock_read_df.return_value = input_df
    expected_rows = input_df.shape[0]
    collapse_columns("in.csv", "out.csv", column_name)
    result_df = mock_save_df.call_args[0][0]

    assert result_df.shape[1] == 1, "Output should have exactly one column"
    assert result_df.shape[0] == expected_rows, "Output should have same number of rows as input"
