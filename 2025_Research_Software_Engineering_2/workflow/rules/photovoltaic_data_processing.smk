# ----------------------------------------------------- #
# Processing of Photovoltaic Data Workflow              #
# ----------------------------------------------------- #



# Processes and cleans the photovoltaic CSV dataset, then extracts specific data types "Electricity feed-in systems"
rule load_and_clean_photovoltaic_data:
	input:
		csv_in = f"{DATA}/pv_data.csv"
	output:
		csv_out = f"{RESULTS}/pv_data_cleaned.csv"
	params:
		label = "Electricity feed-in"
	shell:
		r'"{PYTHON}" "{SRC}/clean_pv_data.py" "{input.csv_in}" "{output.csv_out}" "{params.label}"'


# trim rows from the beginning and end of the photovoltaic CSV file and save the result
rule trim_photovoltaic:
	input:
		f"{RESULTS}/pv_data_cleaned.csv"
	output:
		f"{RESULTS}/pv_data_cleaned_trimmed.csv"
	params:
		arg1 = "0",
		arg2 = "1"
	shell:
		f"{PYTHON} {SRC}/trim.py {{input}} {{output}} {{params.arg1}} {{params.arg2}}"


# Sums each row across all columns of the photovoltaic data and writes the result as a single-column file
rule collapse_columns_photovoltaic:
	input:
		csv_in = f"{RESULTS}/pv_data_cleaned_trimmed.csv"
	output:
		csv_out = f"{RESULTS}/pv_data_cleaned_trimmed_collapsed.csv"
	params:
		column_name = "Energy [kWh]"
	shell:
		f'{PYTHON} "{SRC}/collapse_columns.py" "{{input.csv_in}}" "{{output.csv_out}}" "{{params.column_name}}"'
