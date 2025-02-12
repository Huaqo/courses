import sys
import rasterio
import numpy as np

def create_change_map(old_tif, new_tif, out_tif):
    """
    Creates a change map from two classified TIFF files by:
      1. Cropping both to their overlapping extent.
      2. Encoding changes as (old_class * 10 + new_class).
    
    Parameters
    ----------
    old_tif : str
        Path to the old classified TIFF file.
    new_tif : str
        Path to the new classified TIFF file.
    out_tif : str
        Path to the output change map TIFF file.
    """

    # Open both rasters
    with rasterio.open(old_tif) as src_old, rasterio.open(new_tif) as src_new:
        
        # 1) Check that both have the same CRS
        if src_old.crs != src_new.crs:
            raise ValueError("Error: Old and new rasters must have the same CRS for cropping.")
        
        # 2) Check that both have the same resolution
        #    (assuming square pixels; if not, adjust accordingly)
        old_res = (abs(src_old.transform.a), abs(src_old.transform.e))
        new_res = (abs(src_new.transform.a), abs(src_new.transform.e))
        if not (np.isclose(old_res[0], new_res[0]) and np.isclose(old_res[1], new_res[1])):
            raise ValueError("Error: Old and new rasters do not have the same resolution.")
        
        # 3) Determine the overlapping bounding box
        left = max(src_old.bounds.left, src_new.bounds.left)
        bottom = max(src_old.bounds.bottom, src_new.bounds.bottom)
        right = min(src_old.bounds.right, src_new.bounds.right)
        top = min(src_old.bounds.top, src_new.bounds.top)
        
        if left >= right or bottom >= top:
            raise ValueError("Error: The input rasters have no overlapping extent.")
        
        # 4) Create windows that correspond to this overlapping area
        window_old = src_old.window(left, bottom, right, top)
        window_new = src_new.window(left, bottom, right, top)
        
        # 5) Read the data from each window (single band assumed)
        old_data = src_old.read(1, window=window_old)
        new_data = src_new.read(1, window=window_new)
        
        # 6) Confirm they now have the same shape after cropping
        if old_data.shape != new_data.shape:
            raise ValueError("Error: The cropped rasters do not have the same shape.")
        
        # 7) Generate the change map as old_value * 10 + new_value
        change_data = old_data * 10 + new_data
        
        # 8) Build the output profile
        out_transform = src_old.window_transform(window_old)
        out_profile = src_old.profile.copy()
        out_profile.update({
            'height': old_data.shape[0],
            'width': old_data.shape[1],
            'transform': out_transform,
            'dtype': rasterio.int16,
            'count': 1,
            'compress': 'lzw'   # optional compression
        })
        
        # 9) Write out the change map
        with rasterio.open(out_tif, 'w', **out_profile) as dst:
            dst.write(change_data.astype(rasterio.int16), 1)

def main():
    # Expect exactly three arguments besides the script name
    if len(sys.argv) != 4:
        print("Usage: python change_detection.py <old_classified.tif> <new_classified.tif> <out_change.tif>")
        sys.exit(1)
    
    old_tif_path = sys.argv[1]
    new_tif_path = sys.argv[2]
    out_tif_path = sys.argv[3]
    
    create_change_map(old_tif_path, new_tif_path, out_tif_path)
    print(f"[INFO] Change map created: {out_tif_path}")

if __name__ == "__main__":
    main()
