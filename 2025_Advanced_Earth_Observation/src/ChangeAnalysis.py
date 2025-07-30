import csv
import rasterio
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


class ChangeAnalysis():
    def __init__(self, old_raster_path, new_raster_path, change_raster_path, report_csv_path, report_png_path):

        # Attributes
        self.old_raster_path = old_raster_path
        self.new_raster_path = new_raster_path
        self.change_raster_path = change_raster_path
        self.report_csv_path = report_csv_path
        self.report_png_path = report_png_path

        print("Initializing ChangeAnalysis...\n")

        # Checks
        self._check_resolution()
        self._check_crs()

        # Calculated
        self._compute_overlap_window()
        self._create_change_raster()
        self.change_matrix_np, self.change_matrix = self._create_change_matrix()
        self._create_change_report_csv()

        print("Change analysis completed.\n")

    def _print_pixel_size(self, raster_path):
        with rasterio.open(raster_path) as src:
            transform = src.transform
            pixel_width = abs(transform.a)
            pixel_height = abs(transform.e)
            print("Pixel size:", pixel_width, "x", pixel_height, "metre\n")

    def _get_pixel_size(self, raster_path):
        with rasterio.open(raster_path) as src:
            transform = src.transform
            pixel_width = abs(transform.a)
            pixel_height = abs(transform.e)
            return pixel_width, pixel_height

    def _check_resolution(self):
        self.pixel_size_old = self._get_pixel_size(self.old_raster_path)
        self.pixel_size_new = self._get_pixel_size(self.new_raster_path)
        if self.pixel_size_old != self.pixel_size_new:
            raise ValueError(f"Pixel sizes of the input rasters do not match. Old raster has resolution of: {
                             self.pixel_size_old} and new raster has a resolution of: {self.pixel_size_new}")
        else:
            self.pixel_size = self.pixel_size_old
            print(f"Pixel resolution check passed: {self.pixel_size}\n")

    def _check_crs(self):
        with rasterio.open(self.old_raster_path) as src_old, rasterio.open(self.new_raster_path) as src_new:
            if src_old.crs != src_new.crs:
                raise ValueError(
                    "Error: Old and new rasters must have the same CRS for cropping.")
            else:
                print("CRS check passed.\n")

    def _compute_overlap_window(self):
        print("Computing overlapping window...")
        with rasterio.open(self.old_raster_path) as src_old, rasterio.open(self.new_raster_path) as src_new:
            left = max(src_old.bounds.left, src_new.bounds.left)
            bottom = max(src_old.bounds.bottom, src_new.bounds.bottom)
            right = min(src_old.bounds.right, src_new.bounds.right)
            top = min(src_old.bounds.top, src_new.bounds.top)

            if left >= right or bottom >= top:
                raise ValueError("No overlapping extent.")

            self.bounds = (left, bottom, right, top)
            self.window_old = src_old.window(left, bottom, right, top)
            self.window_new = src_new.window(left, bottom, right, top)
            print(f"Overlap window calculated: {self.bounds}\n")

    def _create_change_raster(self):
        print("Creating change raster...")
        with rasterio.open(self.old_raster_path) as src_old, rasterio.open(self.new_raster_path) as src_new:
            old_data = src_old.read(1, window=self.window_old)
            new_data = src_new.read(1, window=self.window_new)

            if old_data.shape != new_data.shape:
                raise ValueError(
                    "Error: The cropped rasters do not have the same shape.")

            change_data = old_data * 10 + new_data

            out_transform = src_old.window_transform(self.window_old)
            out_profile = src_old.profile.copy()
            out_profile.update({
                'height': old_data.shape[0],
                'width': old_data.shape[1],
                'transform': out_transform,
                'dtype': rasterio.int16,
                'count': 1,
                'compress': 'lzw'
            })

            with rasterio.open(self.change_raster_path, 'w', **out_profile) as dst:
                dst.write(change_data.astype(rasterio.int16), 1)
        print(f"Change raster created and saved to: {
              self.change_raster_path}\n")

    def _create_change_matrix(self):
        print("Creating change matrix...")
        with rasterio.open(self.change_raster_path) as dataset:
            change_data = dataset.read(1)

            flat_data = change_data.flatten()

            nodata = dataset.nodata
            if nodata is not None:
                flat_data = flat_data[flat_data != nodata]

            old_classes = flat_data // 10
            new_classes = flat_data % 10

            matrix = {}

            for old, new in zip(old_classes, new_classes):
                if (old, new) not in matrix:
                    matrix[(old, new)] = 0
                matrix[(old, new)] += 1

            # Matrix numpy array
            unique_old = sorted(set(old_classes))
            unique_new = sorted(set(new_classes))

            mat_np = np.zeros(
                (max(unique_old)+1, max(unique_new)+1), dtype=int)

            for (old, new), count in matrix.items():
                mat_np[old, new] = count
            print("Change matrix created.\n")
            return mat_np, matrix

    def _create_change_report_csv(self):
        print(f"Writing change matrix to CSV: {self.report_csv_path}")
        with open(self.report_csv_path, mode='w', newline='') as csvfile:
            writer = csv.writer(csvfile)
            header = ['Old/New'] + list(range(self.change_matrix_np.shape[1]))
            writer.writerow(header)

            for old_class, row in enumerate(self.change_matrix_np):
                writer.writerow([old_class] + list(row))
        print("CSV report created.\n")
