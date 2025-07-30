# ----------------------------------------------------- #
# Processing of Sunshine Duration Data Workflow         #
# ----------------------------------------------------- #


# Downloads all files from a URL to a local directory
rule load_sunshine_duration_data:
	output:
		directory(f"{RESULTS}/{SUNSHINE_DATA}/")
	shell:
		f'{PYTHON} {SRC}/wgetdir.py "https://opendata.dwd.de/climate_environment/CDC/regional_averages_DE/monthly/sunshine_duration/" {{output}}'


# Combines twelve CSV files from a directory by selecting German averages into one dataframe
rule merge_series:
    input:
	    f"{RESULTS}/{SUNSHINE_DATA}/"
    output:
	    f"{RESULTS}/sunshine_duration.csv"
    shell:
        f"{PYTHON} {SRC}/merge_series.py {{input}} {{output}}"


# Sums each row across all columns of the sunshiine duration data and write the result as a single-column file
rule collapse_columns_sunshine_duration:
	input:
		f"{RESULTS}/sunshine_duration.csv"
	output:
		f"{RESULTS}/sunshine_duration_yearly.csv"
	params:
		column_name = "Duration [h]"
	shell:
		f'{PYTHON} {SRC}/collapse_columns.py {{input}} {{output}} "{{params.column_name}}"'


# trim rows from the beginning and end of the solarparc CSV file and save the result
rule trim_sunshine_duration:
	input:
		f"{RESULTS}/sunshine_duration_yearly.csv"
	output:
		f"{RESULTS}/sunshine_duration_yearly_trimmed.csv"
	params:
		arg1 = "67",
		arg2 = "0"
	shell:
		f"{PYTHON} {SRC}/trim.py {{input}} {{output}} {{params.arg1}} {{params.arg2}}"


# plots the yearly changes of sunshine duration
rule plot_yearly_change_sunshine:
	input:
		f"{RESULTS}/sunshine_duration_yearly_trimmed.csv"
	output:
		f"{REPORT}/sunshine_duration_yearly_trimmed.png"
	params:
		title = "Sunshine Duration 2018-2024",
		year_filter = None
	shell:
		f'{PYTHON} {SRC}/plot_change.py {{input}} {{output}} "{{params.title}}" {{params.year_filter}}'
