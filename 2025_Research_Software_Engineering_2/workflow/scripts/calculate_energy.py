"""
Calculate theoretical energy generation of solar parks.

This script reads the area of solar parks (in m²) and sunshine duration (in hours),
then calculates the theoretical energy produced (in kWh) using a given efficiency.

Usage:
    python calculate_energy.py <area_data_path> <sunshine_data_path> <output_data_path> <efficiency>

Arguments:
    area_data_path (str or Path):       Path to the input file with solar park area data.
    sunshine_data_path (str or Path):   Path to the input file with sunshine duration data.
    output_data_path (str or Path):     Path where the output file will be saved.
    efficiency (float):                 Average efficiency of PV panels (as a decimal, e.g. 0.15
                                        for 15%)
"""

import os
import sys
import utils
import checks
import logs



def calculate_energy(area_path, sunshine_path, output_path, efficiency):
    """
    Calculate the theoretical energy production of solar parks in kWh.

    Reads input files with solar park area and sunshine duration, then computes
    energy using the formula: energy = area * sunshine_duration * power_per_m2 * efficiency.

    Args:
        area_path (str or Path):     Path to the input file with area data (m²).
        sunshine_path (str or Path): Path to the input file with sunshine duration data (hours).
        output_path (str or Path):   Path to save the calculated energy output CSV.
        efficiency (float):          Average efficiency of PV panels (decimal).

    Returns:
        None: Saves the calculated energy DataFrame to the specified output path.
    """
    logs.log_processing(os.path.basename(__file__))
    logs.log_parameter('efficiency', str(efficiency))
    checks.check_path(area_path)
    checks.check_path(sunshine_path)
    checks.check_dir(output_path)
    checks.check_empty(efficiency)
    content = utils.read_file(area_path)
    area = utils.parse_number(content)
    sunshine_data = utils.read_df(sunshine_path, ",", 0, 0)
    efficiency_number = float(efficiency)
    power_per_m2 = 0.1

    # main calculation
    factor = power_per_m2 * area * efficiency_number
    energy = sunshine_data * factor

    utils.save_df(energy, output_path)
    logs.log_processed(os.path.basename(__file__))


if __name__ == "__main__":
    checks.check_args(5, __doc__)
    calculate_energy(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
