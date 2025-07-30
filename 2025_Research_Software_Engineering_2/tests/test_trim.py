"""
Unit tests for the trim module's trimming functionality.
"""

import pandas as pd
import trim


def test_trim_function(local_tmp_path):
    """Test trimming rows from a CSV file using trim.trim."""
    input_csv = local_tmp_path / "input.csv"
    output_csv = local_tmp_path / "output.csv"
    sample_data = pd.DataFrame({
        "id": [1, 2, 3, 4, 5],
        "name": ["Alice", "Bob", "Charlie", "David", "Eve"],
        "value": [10, 20, 30, 40, 50]
    })

    sample_data.to_csv(input_csv, index=False)
    trim.trim(str(input_csv), str(output_csv), "1", "2")
    result = pd.read_csv(output_csv)
    expected = sample_data.iloc[1:-2]

    pd.testing.assert_frame_equal(result.reset_index(
        drop=True), expected.reset_index(drop=True))
