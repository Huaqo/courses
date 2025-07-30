# ----------------------------------------------------- #
# Calculate Energy and Analysis Workflow                #
# ----------------------------------------------------- #


# Processes photovoltaic and solar datasets to calculate and calculate yearly energy
rule calculate_theoretical_energy:
    input:
        area = f"{RESULTS}/solarparcs_area.txt",
        sunshine_duration = f"{RESULTS}/sunshine_duration.csv"
    output:
        f"{RESULTS}/solarparcs_energy.csv"
    shell:
        f"{PYTHON} {SRC}/calculate_energy.py {{input.area}} {{input.sunshine_duration}} {{output}} {EFFICIENCY}"


# Sums each row across all columns of the solaparc data and writes the result as a single-column file
rule collapse_columns_theoretical_energy:
	input:
		f"{RESULTS}/solarparcs_energy.csv"
	output:
		f"{RESULTS}/solarparcs_energy_yearly.csv"
	params:
		column_name = "Energy [kWh]"
	shell:
		f'{PYTHON} {SRC}/collapse_columns.py {{input}} {{output}} "{{params.column_name}}"'


# trim rows from the beginning and end of the solarparc CSV file and save the result
rule trim_theoretical_energy:
	input:
		f"{RESULTS}/solarparcs_energy_yearly.csv"
	output:
		f"{RESULTS}/solarparcs_energy_yearly_trimmed.csv"
	params:
		arg1 = "67",
		arg2 = "0"
	shell:
		f"{PYTHON} {SRC}/trim.py {{input}} {{output}} {{params.arg1}} {{params.arg2}}"


# plots the yearly changes of solarparc energy
rule plot_yearly_energy_change:
	input:
		f"{RESULTS}/solarparcs_energy_yearly_trimmed.csv"
	output:
		f"{REPORT}/solarparcs_energy_yearly_trimmed.png"
	params:
		title = "Theoretical Energy 2018-2024",
		year_filter=None
	shell:
		f'{PYTHON} {SRC}/plot_change.py {{input}} {{output}} "{{params.title}}" {{params.year_filter}}'


# plots the yearly changes of phtovoltaic energy
rule plot_yearly_change_photovoltaic:
	input:
		f"{RESULTS}/pv_data_cleaned_trimmed_collapsed.csv"
	output:
		f"{REPORT}/pv_data_cleaned_trimmed_collapsed.png"
	params:
		title = "Photovoltaic",
		year_filter=None
	shell:
		f'{PYTHON} {SRC}/plot_change.py {{input}} {{output}} "{{params.title}}" {{params.year_filter}}'


# Calculates and compares yearly energy sums from actual and theoretical solar data
rule calculate_difference:
	input:
		actual = f"{RESULTS}/pv_data_cleaned_trimmed_collapsed.csv",
		theoretical = f"{RESULTS}/solarparcs_energy_yearly_trimmed.csv"
	output:
	 	f"{RESULTS}/energy_difference.csv"
	shell:
		f"{PYTHON} {SRC}/calculate_difference.py {{input.actual}} {{input.theoretical}} {{output}}"


# plots the monthly change of photovoltaic energy
rule plot_monthly_change_photovoltaic:
	input:
		f"{RESULTS}/pv_data_cleaned.csv"
	output:
	 	f"{REPORT}/pv_monthly_change_{YEAR}.png"
	params:
		title = "'Monthly Change Photovoltaic'",
		year_filter={YEAR}
	shell:
		f'{PYTHON} {SRC}/plot_change.py {{input}} {{output}} "{{params.title}}" "{{params.year_filter}}"'


# Plots yearly differences between actual and theoretical photovoltaic energy
rule plot_energy difference:
	input:
		f"{RESULTS}/energy_difference.csv"
	output:
	 	f"{REPORT}/energy_difference.png"
	params:
		title = "Yearly Energy Difference: Actual – Theoretical (kWh)",
		year_filter=None
	shell:
		f'{PYTHON} {SRC}/plot_change.py {{input}} {{output}} "{{params.title}}" {{params.year_filter}}'
