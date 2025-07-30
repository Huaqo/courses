"""Unit tests for the merge_series function"""

import os
import pandas as pd
from merge_series import merge_series


def test_merge_series(local_tmp_path):
    """
    Test that merge_series combines the data and creates
    a non empty CSV.file.
    """
    input_directory = "tests/data/sunshine_duration"
    output_path = local_tmp_path / "merged.csv"
    expected_path = "tests/data/sunshine_duration.csv"

    merge_series(input_directory, output_path)
    expected_data = pd.read_csv(expected_path)
    output_data = pd.read_csv(output_path)

    assert os.path.exists(output_path)
    assert os.path.getsize(output_path) > 0
    pd.testing.assert_frame_equal(expected_data, output_data)
