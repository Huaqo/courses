import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from typing import Dict, List, Tuple

DATA_PATH = "../data/13311-0001_en_flat.csv"

primary_sectors: List[str] = [
    'Agriculture, forestry and fishing',
    'Mining and quarrying',
    'Electricity, gas, steam, air conditioning supply',
    'Water supply,sewerage,waste management,remediation'
]

secondary_sectors: List[str] = [
    'Construction',
    'Manufacturing',
    'Industry',
    'Industry, except construction'
]

tertiary_sectors: List[str] = [
    'Financial, insurance, business, real estate act.',
    'Financial and insurance activities',
    'Real estate activities',
    'Professional, scientific and technical activities',
    'Administrative and support service activities',
    'Business services',
    'Information and communication',
    'Wholesale, retail trade, repair of motor vehicles',
    'Trade, transport., storage, accom.and food service',
    'Trade,transport.,storage,accom.and food serv.,inf.',
    'Transportation and storage',
    'Accommodation and food service activities',
    'Public services, education, health',
    'Public admin. and defence, compulsory social sec.',
    'Education',
    'Human health and social work activities',
    'Public a.other services, education, health,priv.h.',
    'Other service activities',
    'Service activities',
    'Private households',
    'Arts, entertainment and recreation',
    'Arts,entertainm.,recreation,o.service act.,priv.h.'
]


def get_df(sector: str = 'Total',
           etype: str = 'Persons in employment (domestic concept)',
           start_time: int = 1999,
           end_time: int = 2024) -> pd.DataFrame:
    """
    Fetches and processes a DataFrame with employment data
    for a specified sector and employment type over a given time range.

    Args:
        sector (str): The economic sector to filter
        data by (default is 'Total').
        etype (str): The type of employment data to retrieve
        (default is 'Persons in employment (domestic concept)').
        start_time (int): The starting year of the time
        range (default is 1999).
        end_time (int): The ending year of the time range
        (default is 2024).

    Returns:
        pd.DataFrame: The filtered and processed DataFrame
        containing the employment data.
    """
    df: pd.DataFrame = pd.read_csv(DATA_PATH, sep=";")
    df = df[['2_variable_attribute_label',
             'value_variable_label',
             'time',
             'value']]
    if sector != 'All':
        df = df[df['2_variable_attribute_label'] == sector]
    df = df[df['value_variable_label'] == etype]
    df['time'] = pd.to_numeric(df['time'], errors='coerce')
    df = df[(df['time'] >= start_time) & (df['time'] <= end_time)]
    if sector == 'All':
        df = df.sort_values(by='2_variable_attribute_label')
    else:
        df = df.sort_values(by='time')
    df['value'] = pd.to_numeric(df['value'], errors='coerce')
    if sector == 'All':
        df = df.drop(['value_variable_label', 'time'], axis=1)
        df = df[df['2_variable_attribute_label'] != 'Total']
    else:
        df = df.drop(['2_variable_attribute_label',
                     'value_variable_label'], axis=1)
    df = df.dropna()
    return df


def get_sectors() -> np.ndarray:
    """
    Get all unique sector names from the dataset, excluding 'Total'.

    Returns:
        np.ndarray: Array of unique sector names.
    """
    df: pd.DataFrame = pd.read_csv(DATA_PATH, sep=";")
    df = df[['2_variable_attribute_label']]
    df = df[df['2_variable_attribute_label'] != 'Total']
    return pd.unique(df.values.ravel())


def line_plot_df(df: pd.DataFrame, title: str) -> None:
    """
    Create a line plot for a single DataFrame.

    Args:
        df (pd.DataFrame): DataFrame containing 'time' and 'value' columns.
        title (str): Title of the plot.

    Returns:
        None
    """
    plt.plot(df['time'], df['value'], label=title)
    plt.title(title)
    plt.xlabel("Time")
    plt.ylabel("Amount")
    plt.legend()
    plt.show()


def line_plot_multiple_df(labeled_dfs: Dict[str, pd.DataFrame],
                          title: str) -> None:
    """
    Create a line plot for multiple DataFrames, each with its own label.

    Args:
        labeled_dfs (Dict[str, pd.DataFrame]): Dictionary where keys are
        labels and values are DataFrames.
        title (str): Title of the plot.

    Returns:
        None
    """
    for key, df in labeled_dfs.items():
        plt.plot(df['time'], df['value'], label=key)
    plt.title(title)
    plt.xlabel("Time")
    plt.ylabel("Amount")
    plt.legend()
    plt.show()


def map_sector_to_group(sector: str) -> str:
    """
    Map a sector name to its corresponding economic
    group (Primary, Secondary, Tertiary).

    Args:
        sector (str): The name of the sector.

    Returns:
        str: The economic group ('Primary Sector', 'Secondary Sector',
        'Tertiary Sector', or 'Unknown').
    """
    if sector in primary_sectors:
        return 'Primary Sector'
    elif sector in secondary_sectors:
        return 'Secondary Sector'
    elif sector in tertiary_sectors:
        return 'Tertiary Sector'
    else:
        return 'Unknown'


def get_grouped_sector_df() -> pd.DataFrame:
    """
    Create a DataFrame grouping employment values by economic sector group.

    Returns:
        pd.DataFrame: DataFrame with groups ('Primary Sector', etc.)
        and their summed employment values.
    """
    df: pd.DataFrame = get_df(sector='All',
                              etype='Persons in employment (domestic concept)',
                              start_time=1999,
                              end_time=2024)
    df = df.rename(columns={
                   '2_variable_attribute_label': 'sector',
                   'time': 'time',
                   'value': 'value'})
    df['Group'] = df['sector'].apply(map_sector_to_group)
    df = df[df['Group'] != 'Unknown']
    df_grouped = df.groupby('Group')['value'].sum().reset_index()
    return df_grouped


def group_values(values: List[float],
                 labels: List[str],
                 threshold: int = 5) -> Tuple[List[float], List[str]]:
    """
    Group values that are below a threshold percentage
    into a single '<5%' category.

    Args:
        values (List[float]): List of numerical values.
        labels (List[str]): Corresponding labels for each value.
        threshold (int): Minimum percentage to avoid grouping. Defaults to 5%.

    Returns:
        Tuple[List[float], List[str]]: Grouped values
        and corresponding grouped labels.
    """
    total: float = sum(values)
    percentages: List[float] = [(value / total) * 100 for value in values]
    grouped_values: List[float] = []
    grouped_labels: List[str] = []
    other_total: float = 0

    for value, label, percent in zip(values, labels, percentages):
        if percent < threshold:
            other_total += value
        else:
            grouped_values.append(value)
            grouped_labels.append(label)

    if other_total > 0:
        grouped_values.append(other_total)
        grouped_labels.append("<5%")

    return grouped_values, grouped_labels


def sort_values(values: List[float],
                labels: List[str]) -> Tuple[List[float], List[str]]:
    """
    Sort values and their labels in descending order based on the values.

    Args:
        values (List[float]): List of numerical values.
        labels (List[str]): Corresponding labels for each value.

    Returns:
        Tuple[List[float], List[str]]: Sorted values and labels.
    """
    sorted_pairs: List[Tuple[float, str]] = sorted(
        zip(values, labels), reverse=True)
    sorted_values, sorted_labels = zip(*sorted_pairs)
    return sorted_values, sorted_labels


def pie_plot_df(values: List[float], labels: List[str], title: str) -> None:
    """
    Create a pie chart from values and labels, grouping small values.

    Args:
        values (List[float]): List of numerical values.
        labels (List[str]): Corresponding labels.
        title (str): Title of the plot.

    Returns:
        None
    """
    grouped_values, grouped_labels = group_values(values, labels, 5)
    sorted_values, sorted_labels = sort_values(grouped_values, grouped_labels)
    plt.pie(x=sorted_values, labels=sorted_labels, autopct='%1.1f%%')
    plt.axis('equal')
    plt.title(title)
    plt.show()


def pie_plot_grouped_sector(df_grouped: pd.DataFrame, title: str) -> None:
    """
    Create a pie chart from a grouped sector DataFrame.

    Args:
        df_grouped (pd.DataFrame): DataFrame with 'Group' and 'value' columns.
        title (str): Title of the plot.

    Returns:
        None
    """
    plt.figure(figsize=(8, 8))
    plt.pie(x=df_grouped['value'],
            labels=df_grouped['Group'],
            autopct='%1.1f%%',
            startangle=140)
    plt.title(title)
    plt.axis('equal')
    plt.show()


def persons_in_employment_timeline() -> None:
    """
    Plot a timeline of total persons in employment from 1999 to 2024 in Germany.

    Returns:
        None
    """
    df_total = get_df()
    line_plot_df(df_total,
                 'Persons in Employment from 1999-2024 in GER')


def employment_types_timeline() -> None:
    """
    Plot timelines comparing employees and self-employed persons 
    from 1999 to 2024 in Germany.

    Returns:
        None
    """
    empl_attr = 'Employees (domestic concept)'
    self_empl_attr = 'Self-employed persons a. family workers (domestic)'
    employment_data_by_type = {
        empl_attr: get_df(etype=empl_attr),
        self_empl_attr: get_df(etype=self_empl_attr)
    }
    line_plot_multiple_df(employment_data_by_type,
                          'Employment types from 1999-2024 in GER')


def employed_per_sector_2024() -> None:
    """
    Create a pie chart showing the distribution of employees across sectors
    in Germany for the year 2022.

    Returns:
        None
    """
    df_sectors_2022 = get_df(
        sector='All',
        etype='Employees (domestic concept)',
        start_time=2022,
        end_time=2022)
    labels = df_sectors_2022['2_variable_attribute_label'].tolist()
    pie_plot_df(values=df_sectors_2022['value'].to_list(
    ), labels=labels, title='Most Employed per sector in 2022 in GER')


def self_employed_per_sector_2024() -> None:
    """
    Create a pie chart showing the distribution of self-employed persons
    across sectors in Germany for the year 2022.

    Returns:
        None
    """
    df_self_sectors_2022 = get_df(
        sector='All',
        etype='Self-employed persons a. family workers (domestic)',
        start_time=2022,
        end_time=2022)
    labels = df_self_sectors_2022['2_variable_attribute_label'].tolist()
    pie_plot_df(values=df_self_sectors_2022['value'].to_list(
    ),
        labels=labels,
        title='Most Self-Employed per sector in 2022 in GER')


def biggest_employment_sectors_timeline() -> None:
    """
    Plot timelines of employment data for the most significant sectors
    in Germany from 1999 to 2024.

    Returns:
        None
    """
    dict_sectors = {
        'Service activities': get_df(sector='Service activities'),
        'Private households': get_df(sector='Private households'),
        'Education': get_df(sector='Education'),
        'Trade,transport.,storage,accom.and food serv.,inf.': get_df(
            sector='Trade,transport.,storage,accom.and food serv.,inf.'),
        'Business services': get_df(sector='Business services'),
        'Public services, education, health': get_df(
            sector='Public services, education, health'),
        'Manufacturing': get_df(sector='Manufacturing')
    }

    emp_sector_title = 'Biggest sectors from 1999-2024 in GER'
    line_plot_multiple_df(dict_sectors, emp_sector_title)


def economic_sectors() -> None:
    """
    Create a pie chart showing the total employment distribution
    by economic sector group (Primary, Secondary, Tertiary).

    Returns:
        None
    """
    df_grouped_sector = get_grouped_sector_df()
    pie_plot_grouped_sector(
        df_grouped_sector, 'Employment Distribution by Economic Sector')


if __name__ == "__main__":
    persons_in_employment_timeline()
    employment_types_timeline()
    employed_per_sector_2024()
    self_employed_per_sector_2024()
    biggest_employment_sectors_timeline()
    economic_sectors()
