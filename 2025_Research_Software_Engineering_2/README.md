# SolarLytics

## Overview

Solarlytics is a project for the Research Software Engineering course at the University of Potsdam. It aims to calculate the theoretical energy production of German solar parks. To do so, it queries the area of solar parks in Germany from OpenStreetMap (OSM) as well as the sunshine duration from the German Weather Service (DWD). The results will be compared with electricity feed-in by photovoltaics.

This project investigates the following research questions related to the theoretical energy production of solar parks in Germany:

**1. What is the spatial distribution and total surface area of solar parks in Germany?** <br>
&nbsp;&nbsp;&nbsp;&nbsp; Using geospatial data from OpenStreetMap (OSM), we aim to identify the location and size of solar parks across the country.
<br>

**2. To what extent can theoretical solar energy production be estimated for the year 2024 by combining solar park area data with sunshine duration data?**<br>
&nbsp;&nbsp;&nbsp;&nbsp; By integrating OSM data with meteorological data from the German Weather Service (DWD), we estimate the potential photovoltaic energy output for each region.
<br>

**3. How does the estimated theoretical energy production compare to the actual electricity feed-in reported by the Federal Statistical Office?** <br>
&nbsp;&nbsp;&nbsp;&nbsp; Significant deviations between theoretical and real production values may point to inefficiencies, data limitations, or external influencing factors. <br>
&nbsp;&nbsp;&nbsp;&nbsp; If significant discrepancies are observed are potential causes for discrepancies between theoretical and actual photovoltaic energy production?
<br>

**4. What are the temporal patterns of theoretical solar energy production throughout the year?** <br>
&nbsp;&nbsp;&nbsp;&nbsp; We analyze monthly trends and investigate whether seasonal or interannual differences can be observed.<br>
&nbsp;&nbsp;&nbsp;&nbsp; How do year-to-year variations in sunshine duration impact theoretical solar energy yield?
<br>

## Activity Diagram

This is a short overview of the process with the four main components of the data processing of solarparc, sunshine duration and photovoltaic data and the subsequent analysis. More details can be found in the documentation under `docs\requirements.md`.

![Alt-Text](/docs/UML_diagram_overview.png)
<br>

## Getting Started
### Requirements

- **Python**    3.13.5  
- **git**      2.39.5  

All additional Python package dependencies are listed in `requirements.txt`.

### Installation

#### Clone the repositpory
The repository can be cloned with the following command:
```bash
git clone https://gitup.uni-potsdam.de/gottlebe/solarlytics.git
```

#### Change directory

```bash
cd solarlytics
```

#### Set up enviroment
The `requirements.txt` file can now be used to create an environment as follows:
Creates a virtual environment named `venv` using Python
```bash
python3 -m venv venv
```
Activates the virtual environment, so any `pip` or `python` commands now use the local environment, not the global Python installation.

```bash
source venv/bin/activate
```
Installs all Python packages listed in the `requirements.txt` file into the virtual environment.
```bash
pip3 install -r requirements.txt
```


## Usage
To run the complete analysis pipeline, simply execute:

```bash
snakemake --cores 1 --forceall
```
This runs Snakemake, using 1 CPU core, and forces all steps to run again, even if their outputs already exist.


This will automatically do the calculation described in the UML-Diagram:
- Download and process the required datasets (OpenStreetMap and DWD),
- Compute the theoretical solar energy production for German solar parks,
- Compare results with actual photovoltaic electricity feed-in data,
- Generate plots, diagrams, and a final report.

All new data frames are saved in the `results/` directory. The report's images and files are saved under `workflow/reports/` and can also be viewed in the automatically generated *slides* (.md) under `docs/`.


## Specific Usage

To remove all results, run:

```bash
snakemake --cores 1 clean
```

To run all unittests, use the following command:

```bash
pytest
```

### Parameterisation
You can customize the analysis by modifying parameters in the `config/config.yml` file. Specifically:

**year**: Defines the year to be analyzed.

**efficiency**: Specifies the average efficiency of the solar parcs, energy feed in and solar radiation (defined as a decimal, e.g. 0.15 for 15%). 

Adjusting these values allows flexible evaluation for different scenarios or datasets.

## Data
This Project uses three datasets:

#### Solarparc Data

To get the area of all solarparks in germany, we use data from Open Street Maps. We use polygons (outlines) of the solarparcs and the outline of germany.

| Data  | Solarparc Data  |
|----------|----------|
| Origin  | Open Steet Maps  |
| Data format  | OSM XML |
| API   | OverpassAPI|
| Link   | https://www.openstreetmap.org/ |
| Licence  |  Data © OpenStreetMap contributors, licensed under Open Database License (ODbL) v1.0 |

#### Photovoltaik Electricity Feed-in Data

Statistics on the monthly electricity feed-in of various energy sources by the Federal Statistical Office of Germany (Destatis). It is possible to show or hide different properties. In this project, the electricity feed-in from photovoltaic systems monthly and over several years is of interest.

| Data  | Photovoltaic Data  |
|----------|----------|
| Origin  | DESTATIS  |
| Data format  | CSV oder XML |
| Link   | https://www-genesis.destatis.de/datenbank/online/statistic/43312/table/43312-0001 |
| Licence  | Data Licence Germany 2.0. |

#### Sunshine Duration Data

The DWD provides many different datasets on sunshine duration. We decided to use the monthly German averages.

| Data  | Sunshine Duration Data |
|----------|----------|
| Origin  | DWD |
| Data format  | TXT |
| Link   | [opendata.dwd.de/climate_environment/CDC/regional_averages_DE/monthly/sunshine_duration/](opendata.dwd.de/climate_environment/CDC/regional_averages_DE/monthly/sunshine_duration/) |
| Licence  |  CC-BY-4.0 |


## Contribution


Contributions are welcome and encouraged! If you would like to contribute to this project, please first read our [Contribution Guidelines](CONTRIBUTING.md) to understand the development workflow and code standards.

We also expect all contributors to follow our [Code of Conduct](CONDUCT.md) to ensure a respectful and inclusive environment.

If you're looking for a place to start, check out the [open issues](https://gitup.uni-potsdam.de/gottlebe/solarlytics/-/issues).


## License

**OpenStreetMap data**:
  Data © OpenStreetMap contributors, licensed under the Open Database License (ODbL) v1.0.
  See https://www.openstreetmap.org/copyright for details.

**Project code and reports**:
  This project is licensed under the MIT License – see [LICENSE](https://gitup.uni-potsdam.de/gottlebe/solarlytics/-/blob/main/LICENSE) file in this repository.

This means you can freely use and modify the code.
If you ever publish processed OSM datasets, those must remain under ODbL with proper attribution.

## Citation
If you use this software, please cite it as described in the [CITATION.cff](https://gitup.uni-potsdam.de/gottlebe/solarlytics/-/blob/tree/main/CITATION.cff) file.

Example citation (in APA format):

Gottlebe, J. Grellmann F., Rupinski M. (2025). SolarLytics: Estimating theoretical solar energy production in Germany (Version 1.0) [Computer software]. https://gitup.uni-potsdam.de/gottlebe/solarlytics

## Contact
For questions or feedback, feel free to reach out via e-mail:
#### Owner:
- Joaquin Gottlebe: gottlebe@uni-potsdam.de

#### Maintainer:
- Flora Grellmann: grellmann@uni-potsdam.de
- Mirjam Rupinski: rupinski@uni-potsdam.de

#### Contributors:
\-


