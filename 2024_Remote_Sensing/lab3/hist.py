import argparse
import rasterio
import numpy as np
import matplotlib.pyplot as plt

def plot_histogram(tiff_path, output_path=None):
    """Plot a linear histogram for a given TIFF file and save it if an output path is provided."""
    try:
        with rasterio.open(tiff_path) as src:
            data = src.read(1)  # Read the first band
            
            # Mask nodata values
            if src.nodata is not None:
                data = np.ma.masked_equal(data, src.nodata)
            
            # Flatten the array to 1D for histogram plotting
            data = data.compressed() if np.ma.isMaskedArray(data) else data.flatten()
            
            # Plot the histogram
            plt.figure(figsize=(10, 6))
            plt.hist(data, bins=256, range=(np.min(data), np.max(data)), edgecolor='black', alpha=0.7)
            plt.title(f"Histogram of {tiff_path}")
            plt.xlabel("Pixel Value")
            plt.ylabel("Frequency")
            plt.grid(axis='y', alpha=0.75)

            # Save the plot if an output path is specified
            if output_path:
                plt.savefig(output_path, dpi=300)
                print(f"Histogram saved to {output_path}")
            else:
                plt.show()
    except Exception as e:
        print(f"Error processing file {tiff_path}: {e}")

def main():
    parser = argparse.ArgumentParser(description="Plot a histogram for a TIFF file.")
    parser.add_argument("tiff_path", help="Path to the TIFF file.")
    parser.add_argument("--output", help="Path to save the histogram plot (optional).", default=None)
    
    args = parser.parse_args()
    
    plot_histogram(args.tiff_path, args.output)

if __name__ == "__main__":
    main()
