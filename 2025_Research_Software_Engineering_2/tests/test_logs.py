"""
Unit tests for logging functions.
"""
from unittest.mock import patch
import logs


def test_log_processing():
    """Test logging of processing start."""
    with patch('logging.info') as mock_info:
        logs.log_processing("ToolA")
        mock_info.assert_called_once_with("Processing %s:", "ToolA")


def test_log_processed():
    """Test logging of processing completion."""
    with patch('logging.info') as mock_info:
        logs.log_processed("ToolB")
        mock_info.assert_called_once_with("Processed: %s", "ToolB")


def test_log_read():
    """Test logging of file read event."""
    with patch('logging.info') as mock_info:
        logs.log_read("/path/to/file.txt")
        mock_info.assert_called_once_with("Read: %s", "/path/to/file.txt")


def test_log_read_error():
    """Test logging of file read error."""
    with patch('logging.error') as mock_error:
        logs.log_read_error("/path/to/missing_file.txt")
        mock_error.assert_called_once_with(
            "Failed to read: %s", "/path/to/missing_file.txt")


def test_log_saved():
    """Test logging of file save event."""
    with patch('logging.info') as mock_info:
        logs.log_saved("/path/to/save_location.txt")
        mock_info.assert_called_once_with(
            "Saved: %s", "/path/to/save_location.txt")


def test_log_saved_error():
    """Test logging of file save error."""
    with patch('logging.error') as mock_error:
        logs.log_saved_error("/path/to/save_location.txt")
        mock_error.assert_called_once_with(
            "Failed to save: %s", "/path/to/save_location.txt")


def test_log_parameter():
    """Test logging of parameter."""
    with patch('logging.info') as mock_info:
        logs.log_parameter('parameter_name', str(999))
        mock_info.assert_called_once_with(
            "Tool runs with %s: %s", "parameter_name", str(999)
        )


def test_log_intensive():
    """Test logging warning for ressource intensiveness."""
    with patch('logging.warning') as mock_info:
        logs.log_intensive()
        mock_info.assert_called_once_with("Tool is resource intensive")
