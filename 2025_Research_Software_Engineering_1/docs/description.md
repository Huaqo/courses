*Exploratory data analysis on employment in Germany*

The dataset 13311-0001 of the Statistischen Bundesamts (Destatis) 
was choosen as the dataset of this project. It was choosen because the author is currently
searching for employment and is therefore interested in insights into structures and trends
of the employment market and regional distribution. The dataset differentiates between 
work-sektors and between Self-employed, employed and domestic employed. 
The dataset has a temporal scope from 1991 to 2024, so 33 years.

Link: https://www-genesis.destatis.de/datenbank/online/statistic/13311/table/13311-0001

## Question 1: Which working sectors in Germany had the most and the fewest employees over the years?

**Answer**:  
A **line plot** showing the number of employees per sector from 1999 to 2024 using total employment data.

- **x-axis**: Year  
- **y-axis**: Number of employees  
- **Color**: One line per sector  
- **Tools**: `pandas`, `matplotlib`  
- **Function used**: `biggest_employment_sectors_timeline()`  

## Question 2: Which sectors in Germany employed the most and the fewest domestic employees over the years?

**Answer**:  
Same line plot as Question 1, but filtered by **domestic concept** employment data.

- **Data filtered with**: `etype='Employees (domestic concept)'`  
- **Tools**: `get_df`, `line_plot_multiple_df`

## Question 3: Which sectors had the most and the fewest self-employed individuals over the years?

**Answer**:  
Line plot using self-employment data across sectors from 1999 to 2024.

- **Employment type**: `Self-employed persons a. family workers (domestic)`  
- **Tools**: `get_df`, `line_plot_multiple_df`  

## Question 4: Which sectors grew or declined the most in employment over the years?

**Answer**:  
A **heatmap** (to be implemented) that visualizes change in employment per sector over time.

- **x-axis**: Year  
- **y-axis**: Sector  
- **Color scale**: Number of employees (intensity = magnitude)  
- **Tools**: `pandas`, `matplotlib`  

## Question 5: How did different employment types evolve over time?

**Answer**:  
A line plot comparing the number of employees vs. self-employed individuals from 1999 to 2024.

- **x-axis**: Year  
- **y-axis**: Number of employees  
- **Lines**: One for each employment type  
- **Function**: `employment_types_timeline()`  
- **Tools**: `pandas`, `matplotlib`
