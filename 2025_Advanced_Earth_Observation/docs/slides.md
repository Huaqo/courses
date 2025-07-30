---
marp: true
theme: uncover
class: invert
paginate: true
_paginate: false
footer: '07.07.2025 / University of Potsdam / Joaquin Gottlebe, Florian Ringel'
---

<!-- _paginate: skip -->
# Artificial Surface Materials at Golm

---

##### Research Question

Which artificial surface material types expanded the most and how much (in $m^2$) between 2018-2024?

---

##### Definition

**Artifical Surface Materials**: Materials, that are located on the surface and are either Man-made or deliberately placed there by humans.

---

##### Study area Campus Golm

![w:550](../data/golm.png)

---

##### Workflow

1. Preprocessing of data
2. Create training data
2. Classification
3. Change detection 
4. Change analysis

---

##### Classes

![w:600](../results/metadata.png)

---

##### Datasets

![100%](../results/empty.png)
![bg 100%](../results/meta_2018.png)
![bg 100%](../results/meta_2024.png)

---

##### Classification Method

1. Read raster **bands**
2. Apply **PCA** to reduce spectral dimensionality
3. Rasterize training polygons into **labeled pixels**
4. Extract labeled pixels as training samples
5. Train **Random Forest** on labeled data
6. Classify all pixels using trained model
7. Validate with validation data

---

##### Classification Implementation

- rasterio
- geopandas
- sklearn.decomposition.PCA
- sklearn.ensemble.RandomForestClassifier

---
##### Classification Training Data

![100%](../results/empty.png)
![bg 100%](../results/training_2018_meta.png)
![bg 100%](../results/training2018.png)

---

##### Classification Training Data

![100%](../results/empty.png)
![bg 100%](../results/training_2024_meta.png)
![bg 100%](../results/training2024.png)

---

##### Classification Results

![100%](../results/empty.png)
![bg 100%](../results/classified_2018.png)
![bg 100%](../results/classified_2024.png)

---

##### Classification Confusion Matrix


![100%](../results/empty.png)
![bg 100%](../results/confusion_matrix_2018.png)
![bg 100%](../results/confusion_matrix_2024.png)

---

##### Classification Accuracy

![100%](../results/empty.png)
![bg 100%](../results/accuracy_2018.png)
![bg 100%](../results/accuracy_2024.png)

---

##### Change Detection Method

$$
\text{change\_value} = \text{old\_value} \times 10 + \text{new\_value}
$$

---

##### Change Detection Results

11
12
13
...
88

![bg right:50% 100%](../results/change.png)

--- 

##### Change Analysis 2018-2024

![w:750](../results/difference.png)

---

##### Challenges

- Datasets had different amount of Bands
- Deciding on the right classes
- Classification with Enmap Box, unsatisfactory

---

Thank you, for your attention!

---

##### Sources

<style scoped>
section {
    font-size: 20px;
}
</style>


Balsamo et al. “Satellite and In Situ Observations for Advancing Global Earth Surface Modelling: A Review.” Remote Sensing 10, no. 12 (December 2018): 2038. https://doi.org/10.3390/rs10122038.

Guanter et al. “The EnMAP Spaceborne Imaging Spectroscopy Mission for Earth Observation.” Remote Sensing 7, no. 7 (July 2015): 8830–57. https://doi.org/10.3390/rs70708830.

Ilehag et al. “KLUM: An Urban VNIR and SWIR Spectral Library Consisting of Building Materials.” Remote Sensing 11, no. 18 (January 2019): 2149. https://doi.org/10.3390/rs11182149.

Lindeni et al.  “Imaging Spectroscopy of Urban Environments.” Surveys in Geophysics 40, no. 3 (May 1, 2019): 471–88. https://doi.org/10.1007/s10712-018-9486-y.

Okujeni et al.  “Support Vector Regression and Synthetically Mixed Training Data for Quantifying Urban Land Cover.” Remote Sensing of Environment 137 (October 1, 2013): 184–97. https://doi.org/10.1016/j.rse.2013.06.007.

Zhao et al. “ASI: An Artificial Surface Index for Landsat 8 Imagery.” International Journal of Applied Earth Observation and Geoinformation 107 (March 1, 2022): 102703. https://doi.org/10.1016/j.jag.2022.102703.

