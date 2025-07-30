# ----------------------------------------------------- #
# Processing of Solarparc Data Workflow                 #
# ----------------------------------------------------- #


# performs spatial clipping of Geopackages using GeoPandas
rule load_solarparc_and_border_data:
    input:
        solarparcs = f"{DATA}/solarparcs.gpkg",
        germany = f"{DATA}/germany.gpkg"
    output:
        f"{RESULTS}/solarparcs_clipped.gpkg"
    shell:
        f"{PYTHON} {SRC}/clip.py {{input.solarparcs}} {{input.germany}} {{output}}"


# Reads geographic data, plots it on a base map, and saves the visualization as an image
rule plot_solarparc_map:
    input:
        clipped = f"{RESULTS}/solarparcs_clipped.gpkg",
        germany = f"{DATA}/germany.gpkg"
    output:
        f"{REPORT}/solarparcs.png"
    shell:
        f'{PYTHON} {SRC}/plot_geo.py {{input.clipped}} {{input.germany}} {{output}} "Solarparcs in Germany 2025"'


# Calculate and compare yearly energy sums from actual and theoretical solar data
rule calculate_area:
    input:
        f"{RESULTS}/solarparcs_clipped.gpkg"
    output:
        f"{RESULTS}/solarparcs_area.txt"
    shell:
        f"{PYTHON} {SRC}/polygons2area.py {{input}} {{output}} m"
