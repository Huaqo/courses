"""Unit tests for the calculate_energy function """

import os
import pandas as pd
from calculate_energy import calculate_energy


def test_calculate_energy(local_tmp_path):
    """
    Test that calculate_energy processes solarparc area and sunshine data to compute
    energy output, and writes the result to a non-empty CSV file.
    """
    area_data_path = "tests/data/area_easy.txt"
    sunshine_data_path = "tests/data/sunshine_duration.csv"
    output_path = local_tmp_path / "energy.csv"
    expected_path = "tests/data/solarparc_energy.csv"

    calculate_energy(area_data_path, sunshine_data_path, output_path, 1)
    expected_data = pd.read_csv(expected_path)
    output_data = pd.read_csv(output_path)

    assert os.path.exists(output_path)
    pd.testing.assert_frame_equal(expected_data, output_data)
