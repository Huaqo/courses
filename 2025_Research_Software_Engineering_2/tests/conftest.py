"""
Shared test fixtures for pytest.

This file defines reusable fixtures that are automatically discovered by pytest
and can be used across multiple test modules.

Fixtures:
---------
- local_tmp_path: Creates (or cleans) a temporary directory under 'tests/tmp'
  to store output files generated during tests. Ensures a clean environment
  for each test run.
"""

from pathlib import Path
import pytest


@pytest.fixture
def local_tmp_path():
    """Fixture to create and return a temporary path for output files."""
    path = Path("tests/tmp")
    if path.exists():
        for file in path.iterdir():
            file.unlink()
    else:
        path.mkdir(parents=True)
    return path
