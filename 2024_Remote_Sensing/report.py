import rasterio
import numpy as np
import pandas as pd

def map_two_digit_code(code: int) -> str:
    """
    Returns a string label like 'Water -> Agriculture'
    by interpreting the tens digit as the 'from' class
    and the ones digit as the 'to' class.

    Example:
      code = 34
      tens_digit = 3 -> 'Forest'
      ones_digit = 4 -> 'Agriculture'
      return 'Forest -> Agriculture'
    """
    # Define what each digit means
    digit_to_label = {
        1: "Water",
        2: "Urban",
        3: "Forest",
        4: "Agriculture"
    }

    # Tens digit = 'from' class
    tens_digit = code // 10
    from_label = digit_to_label.get(tens_digit, "Unknown")

    # Ones digit = 'to' class
    ones_digit = code % 10
    to_label = digit_to_label.get(ones_digit, "Unknown")

    return f"{from_label} -> {to_label}"

def generate_change_detection_report(tif_path: str, output_csv_path: str = None) -> pd.DataFrame:
    """
    Reads a single-band change-detection GeoTIFF with classes from 11 to 44,
    generates a report of pixel counts, area, and applies a label for every code.

    :param tif_path: Path to the input GeoTIFF.
    :param output_csv_path: If provided, saves the report as a CSV file.
    :return: A pandas DataFrame with columns: ['Class_Value', 'Pixel_Count', 'Area', 'Label'].
    """
    # 1. Open the raster
    with rasterio.open(tif_path) as src:
        band = src.read(1)
        transform = src.transform
        
        # Compute pixel area
        pixel_width = transform[0]
        pixel_height = -transform[4]  # Typically negative
        pixel_area = pixel_width * pixel_height

    # 2. Count unique class values
    unique_vals, counts = np.unique(band, return_counts=True)

    # 3. Filter classes from 11 to 44
    valid_mask = (unique_vals >= 11) & (unique_vals <= 44)
    filtered_classes = unique_vals[valid_mask]
    filtered_counts = counts[valid_mask]

    # 4. Calculate area per class
    areas = filtered_counts * pixel_area

    # 5. Create a DataFrame
    df_report = pd.DataFrame({
        "Class_Value": filtered_classes,
        "Pixel_Count": filtered_counts,
        "Area": areas
    })

    # 6. Apply the custom mapping function to get a text label (e.g., 'Water -> Agriculture')
    df_report["Label"] = df_report["Class_Value"].apply(map_two_digit_code)

    # 7. (Optional) sort by Class_Value
    df_report.sort_values(by="Class_Value", inplace=True)

    # 8. Optionally save the DataFrame to a CSV file
    if output_csv_path:
        df_report.to_csv(output_csv_path, index=False)

    return df_report

# ---------------
# Example usage:
if __name__ == "__main__":
    input_tif = "change_detected/change_detection.tif"  # Update path as needed
    report_df = generate_change_detection_report(
        tif_path=input_tif,
        output_csv_path="report/change_detection_report.csv"
    )

    print("Detailed Report (11–44):")
    print(report_df)

    # Optional: Summarize area by the Label column
    summary = report_df.groupby("Label")["Area"].sum().reset_index()
    summary.columns = ["Label", "Total_Area"]
    print("\nArea Summary by Label:")
    print(summary)
