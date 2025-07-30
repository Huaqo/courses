'''
Unit tests for the plot_change function.

These tests use mocking to isolate the function from file I/O,
logging, and plotting. They verify that the function behaves
correctly for both monthly and yearly data formats.
'''
from unittest import mock
import pandas as pd
import matplotlib
import plot_change
matplotlib.use("Agg")


@mock.patch("matplotlib.pyplot.savefig")
@mock.patch("plot_change.utils.read_df")
@mock.patch("plot_change.checks.check_empty")
@mock.patch("plot_change.checks.check_dir")
@mock.patch("plot_change.checks.check_path")
@mock.patch("plot_change.logs.log_processed")
@mock.patch("plot_change.logs.log_processing")
def test_plot_change_yearly(_mock_log_processing, _mock_log_processed,
                            _mock_check_path, _mock_check_dir, _mock_check_empty,
                            mock_read_df, mock_savefig, local_tmp_path):
    """Test yearly data case without year_filter."""
    df = pd.DataFrame({
        "Year": [2018, 2019, 2020],
        "Electricity feed-in": [100000, 110000, 120000]
    })
    mock_read_df.return_value = df

    input_path = "fake_input.csv"
    output_path = local_tmp_path / "output_yearly.png"
    title = "Yearly Plot"

    plot_change.plot_change(str(input_path), str(
        output_path), title, year_filter=None)

    mock_read_df.assert_called_once_with(input_path, ",", 0, None)
    mock_savefig.assert_called_once_with(str(output_path))
