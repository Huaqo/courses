.PHONY: all preproc1 preproc2 proc proc2 maps export

ACTIVATE_SCRIPT = ~/miniforge3/bin/activate
CONDA_ENV_NAME = gdal_env
PANDOC=pandoc

all: preproc1 preproc2 proc proc2 maps export

preproc1:
	gdal_translate -of GTiff /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/S2A_MSIL2A_20170527T102031_N9999_R065_T33UUU_20191015T100203.SAFE/GRANULE/L2A_T33UUU_A010072_20170527T102301/IMG_DATA/R10m/T33UUU_20170527T102031_B02_10m.jp2 /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/sen2tiff/B02.tif && \
	gdal_translate -of GTiff /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/S2A_MSIL2A_20170527T102031_N9999_R065_T33UUU_20191015T100203.SAFE/GRANULE/L2A_T33UUU_A010072_20170527T102301/IMG_DATA/R10m/T33UUU_20170527T102031_B03_10m.jp2 /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/sen2tiff/B03.tif && \
	gdal_translate -of GTiff /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/S2A_MSIL2A_20170527T102031_N9999_R065_T33UUU_20191015T100203.SAFE/GRANULE/L2A_T33UUU_A010072_20170527T102301/IMG_DATA/R10m/T33UUU_20170527T102031_B04_10m.jp2 /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/sen2tiff/B04.tif && \
	gdal_translate -of GTiff /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/S2A_MSIL2A_20170527T102031_N9999_R065_T33UUU_20191015T100203.SAFE/GRANULE/L2A_T33UUU_A010072_20170527T102301/IMG_DATA/R10m/T33UUU_20170527T102031_B08_10m.jp2 /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/sen2tiff/B08.tif

preproc2:
	gdal_translate -of GTiff /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/S2A_MSIL2A_20170527T102031_N9999_R065_T33UUU_20191015T100203.SAFE/GRANULE/L2A_T33UUU_A010072_20170527T102301/IMG_DATA/R10m/T33UUU_20170527T102031_B02_10m.jp2 /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/sen2tiff2/B02.tif && \
	gdal_translate -of GTiff /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/S2A_MSIL2A_20241118T143741_N0511_R096_T18GXU_20241118T201252.SAFE/GRANULE/L2A_T18GXU_A049142_20241118T144600/IMG_DATA/R10m/T18GXU_20241118T143741_B03_10m.jp2 /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/sen2tiff2/B03.tif && \
	gdal_translate -of GTiff /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/S2A_MSIL2A_20241118T143741_N0511_R096_T18GXU_20241118T201252.SAFE/GRANULE/L2A_T18GXU_A049142_20241118T144600/IMG_DATA/R10m/T18GXU_20241118T143741_B04_10m.jp2 /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/sen2tiff2/B04.tif && \
	gdal_translate -of GTiff /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/S2A_MSIL2A_20241118T143741_N0511_R096_T18GXU_20241118T201252.SAFE/GRANULE/L2A_T18GXU_A049142_20241118T144600/IMG_DATA/R10m/T18GXU_20241118T143741_B08_10m.jp2 /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/sen2tiff2/B08.tif
proc:
	@source $(ACTIVATE_SCRIPT) && conda activate $(CONDA_ENV_NAME) && \
	python3 ndvi.py sen2tiff/B04.tif sen2tiff/B08.tif ndvi && \
	python3 ndwi.py sen2tiff/B03.tif sen2tiff/B08.tif ndwi && \
	python clip.py /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/l8_ndvi/l8_ndvi.TIF /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/ndvi/B04_ndvi.TIF /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/clip/l8_ndvi.TIF /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/clip/sen_ndvi.TIF && \
	python diff.py /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/clip/sen_ndvi.TIF /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/clip/l8_ndvi.TIF /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/diff/aligned.TIF /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/diff/diff.TIF && \
	python clip.py /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/l8_ndwi/l8_ndwi.TIF /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/ndwi/B03_ndwi.TIF /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/clip/l8_ndwi.TIF /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/clip/sen_ndwi.TIF && \
	python diff.py /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/clip/sen_ndwi.TIF /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/clip/l8_ndwi.TIF /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/diff/aligned_ndwi.TIF /home/huaqo/dev/courses/2024_Remote_Sensing/lab3/diff/diff_ndwi.TIF && \
	python hist.py diff/diff_ndwi.TIF --output plots/diff_hist.png

proc2:
	@source $(ACTIVATE_SCRIPT) && conda activate $(CONDA_ENV_NAME) && \
	python3 ndvi.py sen2tiff2/B04.tif sen2tiff2/B08.tif ndvi2 && \
	python3 ndwi.py sen2tiff2/B03.tif sen2tiff2/B08.tif ndwi2

maps:
	python3 ndvi_map.py
	python3 ndvi_map2.py
	python3 ndwi_map.py
	python3 ndwi_map2.py
	python3 diff_map.py

export:

	$(PANDOC) Lab3.md -o rcm01_2425_lab3_gottlebe_829101.pdf