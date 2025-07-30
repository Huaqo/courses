"""
Unit tests for the module clean_pv_data.py
"""
from unittest.mock import patch
import pandas as pd
from clean_pv_data import clean_pv_data


@patch("utils.save_df")
@patch("utils.read_df")
@patch("checks.check_empty")
@patch("checks.check_dir")
@patch("checks.check_path")
@patch("logs.log_processing")
@patch("logs.log_processed")
def test_clean_pv_data(_mock_log_processed, _mock_log_processing,
                                _mock_check_path, _mock_check_dir, _mock_check_empty,
                                mock_read_df, mock_save_df):
    """
    Test that clean_pv_data filters by variable label and reshapes the data into
    a wide format by month.
    """
    # Dummy parameter setup
    extracted_type = "Electricity feed-in"
    inputh_path = "dummy_input.csv"
    output_path = "dummy_output.csv"

    input_data = pd.DataFrame({
        "time": ["2022", "2022", "2022"],
        "1_variable_attribute_label": ["January", "February", "January"],
        "value": [100, 150, 300],
        "value_variable_label": ["Electricity feed-in",
                                 "Electricity feed-in",
                                 "Net nominal capacity"]
    })
    mock_read_df.return_value = input_data

    clean_pv_data(inputh_path, output_path, extracted_type)
    result_df = mock_save_df.call_args[0][0]

    assert "January" in result_df.columns
    assert "February" in result_df.columns
    assert result_df.loc["2022", "January"] == 100
    assert result_df.loc["2022", "February"] == 150
    assert "Net nominal capacity" not in result_df.values
