.PHONY: all run pdf clean

PYTHON=venv/bin/python
PANDOC=pandoc

all: run pdf

run:
	$(PYTHON) script.py
pdf:
	$(PANDOC) Lab1.md -o rcm01_2425_lab1_gottlebe_829101.pdf