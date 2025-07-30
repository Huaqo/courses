# SolarLytics Requirements

## Functional Requirements
#### UML Diagram

Main diagram describing the process of the complete project:
<br> ![Alt-Text](/docs/UML_diagram_overview.png)

The individual processing steps of the different datasets are shown here in more detail:
<br> ![Alt-Text](/docs/UML_diagram_detail.png)


## Non-functional Requirements

### Must Have

- **Compatibility**: The workflow must run on Windows and Mac OS. It should be easy to deploy and run in different environments.
- **Documentation**: The documentation is for users and developers and must be available, including metadata, license information, a read-me file, and citation as well as contributing guidelines.
- **Reproducibility**: The workflow must be reproducible.
- **Testability**: The code must be well tested, with unit and integration tests in place.

### Should Have

- **Performance**: The workflow should able to process the datasets in a reasonable time.
- **Maintainability**: The code should be well modularized and organized, following the standard template and PEP 8 guidelines. It should be refactured regularily.
- **Easy-to-Use**: The workflow should provide a easy user experience

### Could Have

- **Accessibility**: The documentation could be translated to German.
- **Presentation**: The workflow could have a visual support in the form of graphics.

### Won't Have

- **Add-ons**: Function for other countries.


# Component Analysis

| Abstract Workflow Node (Operation) | Input(s)                                  | Output(s)                             |Implementation                               |
|------------------------------------|-------------------------------------------|---------------------------------------|----------------------------------------------|
|**photovoltaic data processing**      |                                         |                                       |
| load and clean photovoltaics data  | original dataset (.csv) from destatis     | dataframe (.csv)                      | CLI tool built on pandas
| trim photovoltaic                  | dataframe (.csv)                          | dataframe(.csv)                       | CLI tool built on pandas
| collapse columns photovoltaic      | dataframe (.csv)                          | dataframe (.csv)                      | CLI tool built on pandas
|                                    |                                           |                                       |
|**sunshine duration data processing** |                                         |                                       |
| load sunshine duration data        | DWD Website                               | sunshine duration data (.txt), one file for each month | CLI tool built on requests, os, bs4 and urllib
| merge series          | 12 sunshine duration datasets (.txt)      | processed dataframe (.csv)            | CLI tool built on pandas
| collapse columns sunshine duration | dataframe (.csv)                          | dataframe (.csv)                      | CLI tool built on pandas
| trim sunshine duration             | dataframe (.csv)                          | dataframe (.csv)                      | CLI tool built on pandas
|                                    |                                           |                                       |
|**solarparc data processing**         |                                         |                                       |
| load solarparc data and border data| OverpassAPI                               | .gpkg file (solarparc / border)       | CLI http request over OverpassAPI, osmium, geopandas, shapely
| calculate area                     | .gpkg file                                | .txt with report                      | CLI tool built on geopandas
|                                    |                                           |                                       |
|**analysis**                          |                                         |                                       |
| calculate theoretical energy       | calculate area (.txt) & sunshine duration dataframe (.csv)   | dataframe (.csv)   | CLI tool built on pandas
| collapse columns theoretical energy| dataframe (.csv)                          | dataframe (.csv)                      | CLI tool built on pandas
| trim theoreticalenergy             | dataframe (.csv)                          | energy differnce dataframe (.csv)     | CLI tool built in pandas
| calculate difference               | theoritcal energy (.csv) &  photovoltaic energy (.csv)       | dataframe .csv     | CLI tool built on pandas
| plot energy difference                    | ernergy difference (.csv)                 | diagram over years (.png)             | CLI tool built on matplotlib and pandas
| plot yearly energy change          | dataframe (.csv)                          | diagram over years (.png)             | CLI tool built on matplotlib and pandas
| plot solarparc map                 | .gpkg file (solarparc / border)           | plot of germany (.png)                | CLI tool built on matplotlib and geopandas
| plot yearly change sunshine        | dataframe (.csv)                          | diagram over years (.png)             | CLI tool built on matplotlib and pandas
| plot yearly change photovoltaic    | dataframe (.csv)                          | diagram over years (.png)             | CLI tool built on matplotlib and pandas
| plot monthly change potovoltaic    | dataframe (.csv)                          | diagram over months (.png)            | CLI tool built on matplotlib and pandas
| generate report                    | mutiple inputs (.txt, .png)               | slides (.md)                        | built on markdown
