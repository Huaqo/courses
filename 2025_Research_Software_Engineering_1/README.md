# Exploratory Data Analysis on Employment in Germany (1999–2024)

**Version:** v1.0  

**Description:**  
This notebook presents an exploratory data analysis of employment trends in Germany from 1999 to 2024. Using official data from the German Federal Statistical Office (Destatis), we investigate key patterns in employment over time, with a focus on overall employment trends, the distribution between employment types (employees vs. self-employed), sectoral developments, and structural shifts between economic sectors. The objective is to uncover long-term transformations in the German labor market and highlight significant historical developments.

## 1. Overview

- **Purpose:** This project includes a Jupyter Notebook and a Python script for exploratory data analysis on employment in Germany.
- **Research context:** Developed as coursework for the "Research Software Engineering" module.
- **Notable features:** Analysis includes sectoral comparisons, employment type trends, and structural economic transitions over 25 years.
- **Date of creation:** 14.04.2025

## 2. Project Structure

- **Main folders:**
  - `data/` – Contains raw and processed datasets (.csv)
  - `docs/` – Project markdown description
  - `src/` – Python scripts and notebooks (.py, .ipynb)

- **File formats used:** `.py`, `.ipynb`, `.md`, `.csv`, `.txt`
- **Project size:** ~230 MB

## 3. Installation

### Prerequisites
- Python 3.13.3  
- Packages listed in `requirements.txt`

### Clone the repository

With SSH (Needs SSH key setup):

With HTTPS:

```bash
git clone https://gitup.uni-potsdam.de/gottlebe/eda-employment-germany.git
```

With SSH (Needs SSH key setup):

```bash
git clone git@gitup.uni-potsdam.de:gottlebe/eda-employment-germany.git
```

### Change directory

```bash
cd eda-employment-germany
```
### Environment setup (Optional)

The virtual environment is optional but recommended to avoid package conflicts.

For Linux/MacOS:

```bash
python3 -m venv venv
source venv/bin/activate
```

For Windows:

```bash
python -m venv venv
venv\Scripts\activate
```

### Instructions

```bash
pip install -r requirements.txt
```

## 4. Usage

- Open the Jupyter notebook and run all cells to reproduce the analysis:

```bash
jupyter notebook src/notebook.ipynb
```

## 5. Data

- **Source:** The Genesis portal of the German Federal Statistical Office (Destatis).
- **Content:** Employment data by year, economic sector, and employment type.
- **Format:** CSV files with well-structured tabular data.
- **Preprocessing:** Minor formatting and cleanup included in the script.

## 6. Reproducibility

- Environment can be replicated using `requirements.txt`.

## 7. Contribution

Contributions are welcome. Users can:
- Open issues
- Fork and create pull requests

## 8. License

This project is licensed under the GNU General Public License v3.0.  
You can view the full license text here: [https://www.gnu.org/licenses/gpl-3.0.en.html](https://www.gnu.org/licenses/gpl-3.0.en.html)

## 9. Citation

No formal citation required for this project.

## 10. Contact

- **Name:** Joaquin Gottlebe  
- **Institution:** University of Potsdam  
- **Email:** joa.gottlebe@gmail.com

## 11. Acknowledgments

- Data courtesy of the German Federal Statistical Office (Destatis)
- Project developed as part of the Research Software Engineering course at the University of Potsdam
