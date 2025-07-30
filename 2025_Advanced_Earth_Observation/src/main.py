from ClassificationAnalysis import get_class_frequency
from ChangeAnalysis import ChangeAnalysis
from Classification import classification
from plot_tiff import plot_tiff
from plot_tiff_rgb import plot_tiff_rgb
from plot_tiff_2 import plot_tiff_2
from plot_table import plot_table
from clip_tiff import clip_tiff
from extract_tiff_metadata import extract_tiff_metadata
from load_gpkg_to_df import load_gpkg_to_dataframe
from gpkg2png import gpkg2png
from empty_png import empty_png
from accuracy_assessment import accuracy_assessment
import pandas as pd


def create_accuracy_df(overall_accuracy, kappa):
    data = {
        "Metric": ["Overall Accuracy", "Kappa Coefficient"],
        "Value": [overall_accuracy, kappa]
    }
    df = pd.DataFrame(data)
    return df


def main():

    # empty png
    empty_png('results/empty.png')

    # Paths
    golm = "data/RGBI_10cm_2022.tif"

    hyperspectral_2018_raster = "data/Hyperspectral_2018.tiff"
    hyperspectral_2018_training = "data/training_2018.gpkg"
    classified_2018_raster = "results/classified_2018.tiff"
    classified_2018_map = "results/classified_2018.png"
    classified_2018_table = "results/frequencies_2018.png"

    hyperspectral_2024_raster = "data/Hyperspectral_2024.tif"
    hyperspectral_2024_training = "data/training_2024.gpkg"
    classified_2024_raster = "results/classified_2024.tiff"
    classified_2024_map = "results/classified_2024.png"
    classified_2024_table = "results/frequencies_2024.png"

    metadata = pd.read_csv("data/metadata.csv")
    change = "results/change.tiff"
    report_csv = "results/report.csv"
    report_png = "results/report.png"

    # Classification
    classification(
        hyperspectral_2018_raster,
        hyperspectral_2018_training,
        classified_2018_raster
    )

    classification(
        hyperspectral_2024_raster,
        hyperspectral_2024_training,
        classified_2024_raster
    )
    clip_tiff(classified_2018_raster,
              "data/CampusGolm_Clipper.gpkg", classified_2018_raster)
    clip_tiff(classified_2024_raster,
              "data/CampusGolm_Clipper.gpkg", classified_2024_raster)
    plot_tiff(classified_2018_raster, classified_2018_map,
              metadata, "2018", '#202228')
    plot_tiff(classified_2024_raster, classified_2024_map,
              metadata, "2024", '#202228')

    # Classification accuracy
    result_2018 = accuracy_assessment(
        classified_raster_path=classified_2018_raster,
        reference_points_path='data/validation_2018.gpkg',
        true_class_field="Class_ID"
    )

    cm_2018 = result_2018['confusion_matrix']
    cm_df_2018 = pd.DataFrame(cm_2018, index=metadata['class_name'].to_list(
    ), columns=metadata['class_name'].to_list())
    plot_table(cm_df_2018, 'results/confusion_matrix_2018.png',
               '2018', '#202228', True)

    oa_2018 = "{:.2f}".format(result_2018['overall_accuracy'])
    kp_2018 = "{:.2f}".format(result_2018['kappa_coefficient'])
    df_acc_2018 = create_accuracy_df(oa_2018, kp_2018)
    plot_table(df_acc_2018, 'results/accuracy_2018.png', '2018', '#202228')

    result_2024 = accuracy_assessment(
        classified_raster_path=classified_2024_raster,
        reference_points_path='data/validation_2018.gpkg',
        true_class_field="Class_ID"
    )

    cm_2024 = result_2024['confusion_matrix']
    cm_df_2024 = pd.DataFrame(cm_2024, index=metadata['class_name'].to_list(
    ), columns=metadata['class_name'].to_list())
    plot_table(cm_df_2024, 'results/confusion_matrix_2024.png',
               '2024', '#202228', True)

    oa_2024 = "{:.2f}".format(result_2024['overall_accuracy'])
    kp_2024 = "{:.2f}".format(result_2024['kappa_coefficient'])
    df_acc_2024 = create_accuracy_df(oa_2024, kp_2024)
    plot_table(df_acc_2024, 'results/accuracy_2024.png', '2024', '#202228')

    # Classification Analysis
    classified_2018_class_frequency = get_class_frequency(
        classified_2018_raster, metadata)
    classified_2024_class_frequency = get_class_frequency(
        classified_2024_raster, metadata)
    plot_table(classified_2018_class_frequency,
               classified_2018_table, "2018", "#202228")
    plot_table(classified_2024_class_frequency,
               classified_2024_table, "2024", "#202228")

    # Change Analysis
    change_analysis = ChangeAnalysis(
        classified_2018_raster, classified_2024_raster, change, report_csv, report_png)
    clip_tiff(change,
              "data/CampusGolm_Clipper.gpkg", change)

    report = pd.read_csv(report_csv)
    plot_table(report, report_png, 'Change Report', '#202228')
    plot_tiff_2(change, "results/change.png", '', "#202228")
    # Plot metadata
    metadata_plot = metadata[["class_name", "class_id"]]
    metadata_plot = metadata_plot.rename(
        columns={'class_name': 'Material', 'class_id': 'ID'})
    plot_table(metadata_plot, "results/metadata.png", "", '#202228')

    # Extract metadata
    extract_tiff_metadata(hyperspectral_2018_raster, "results/meta_2018.csv")
    plot_table(pd.read_csv('results/meta_2018.csv'),
               'results/meta_2018.png', '2018', '#202228')
    extract_tiff_metadata(hyperspectral_2024_raster, "results/meta_2024.csv")

    plot_table(pd.read_csv('results/meta_2024.csv'),
               'results/meta_2024.png', '2024', '#202228')
    # Add training data to metadata
    training_2018_meta = load_gpkg_to_dataframe(hyperspectral_2018_training)
    training_2018_meta = training_2018_meta[['name', 'Class_ID']]

    training_2018_meta = (
        training_2018_meta.groupby(['Class_ID', 'name'])
        .size()
        .reset_index(name="count")
    )
    training_2018_meta = training_2018_meta.sort_values(
        by='Class_ID', ascending=True).reset_index(drop=True)

    training_2018_meta = training_2018_meta[['name', 'count']]
    training_2018_meta = training_2018_meta.rename(
        columns={"name": 'Material', "count": 'Samples'})
    plot_table(training_2018_meta,
               "results/training_2018_meta.png", '2018', '#202228')

    training_2024_meta = load_gpkg_to_dataframe(hyperspectral_2024_training)
    training_2024_meta = training_2024_meta[['name', 'Class_ID']]

    training_2024_meta = (
        training_2024_meta.groupby(['Class_ID', 'name'])
        .size()
        .reset_index(name="count")
    )

    training_2024_meta = training_2024_meta.sort_values(
        by='Class_ID', ascending=True).reset_index(drop=True)

    training_2024_meta = training_2024_meta[['name', 'count']]
    training_2024_meta = training_2024_meta.rename(
        columns={"name": 'Material', "count": 'Samples'})
    plot_table(training_2024_meta,
               "results/training_2024_meta.png", '2024', '#202228')

    # Plot training data
    gpkg2png(hyperspectral_2018_training,
             "data/RGBI_20cm_2021.tiff", "results/training2018.png", '2018', "#202228")
    gpkg2png(hyperspectral_2024_training,
             "data/RGBI_20cm_2021.tiff", "results/training2024.png", '2024', "#202228")

    # Diff
    # Merge
    classified_difference = pd.merge(
        classified_2018_class_frequency,
        classified_2024_class_frequency,
        on="class_name",
        how="inner"
    )

    # Compute difference
    classified_difference['change'] = (
        classified_difference['count_y'] - classified_difference['count_x']
    )

    with open('results/area.txt', 'r') as f:
        total_area = float(f.read().strip())

    classified_difference['percent_change'] = (
        (classified_difference['change'] / total_area) * 100
    ).round(2)
    # Sort by 'change'
    classified_difference = classified_difference.sort_values(
        "change", ascending=False
    )

    classified_difference = classified_difference[[
        'class_name', 'change', 'percent_change']]
    classified_difference = classified_difference.rename(
        columns={"class_name": "Material", "change": "Change in m²", "percent_change": "Change in %"})
    plot_table(classified_difference, 'results/difference.png', '', "#202228")


if __name__ == "__main__":
    main()
