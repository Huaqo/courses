
## Setup

### 1. Create and activate a virtual environment

**Linux/macOS:**
```bash
python3 -m venv venv
source venv/bin/activate
```

**Windows:**
```bash
python -m venv venv
venv\Scripts\activate
```

### 2. Install requirements

```bash
pip3 install -r requirements.txt
```

### 3. Run the main script

```bash
python3 src/main.py
```

### 4. Update Slides

edit `docs/slides.md`

### 5. Compile html

Requirements: marp

```
marp docs/slides.md
```

### 5. View slides

Open `docs/slides.html` in your browser
