"""
Logging setup and helper functions for processing events.

Configures logging to file and console, with functions
to log start, completion, and saving steps of processing.
Containing logs:
- processing
- processed
- read
- read error
- saved
- saved error
- parameter
- intensive
"""

import logging

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s - %(levelname)s - %(message)s",
    handlers=[
        logging.FileHandler("log.txt"),
        logging.StreamHandler()
    ]
)


def log_processing(tool_name):
    """
    Logs the start of processing for a given tool.

    Args:
        tool_name (str): Name of the tool being processed.

    Returns:
        None
    """
    logging.info("Processing %s:", tool_name)


def log_processed(tool_name):
    """
    Logs the successful completion of processing for a given tool.

    Args:
        tool_name (str): Name of the tool that has been processed.

    Returns:
        None
    """
    logging.info("Processed: %s", tool_name)


def log_read(path):
    """
    Logs the reading of a file from a given path.

    Arguments:
        path (str): Path to file which were read.

    Returns:
        None
    """
    logging.info("Read: %s", path)


def log_read_error(path):
    """
    Logs the reading error of a given path.

    Arguments:
        path (str): Path were the file should be read.

    Returns:
        None
    """
    logging.error("Failed to read: %s", path)


def log_saved(path):
    """
    Logs the saving of output to a given path.

    Args:
        path (str): Path where the output was saved.

    Returns:
        None
    """
    logging.info("Saved: %s", path)


def log_saved_error(path):
    """
    Logs the saving error of output to a given path.

    Arguments:
        path (str): Path were the output should be saved.

    Returns:
        None
    """
    logging.error("Failed to save: %s", path)


def log_parameter(parameter_name, parameter_value):
    """
    Logs a  parameter.

    Arguments:
        parameter_name (str): Parameter name with which the tool is called.
        parameter_value (str): Parameter value with which the tool is called.

    Returns:
        None
    """

    logging.info("Tool runs with %s: %s", parameter_name, parameter_value)


def log_intensive():
    """
    Logs warning for resource intensiveness.

    Arguments:
        None
    Returns:
        None
    """
    logging.warning("Tool is resource intensive")
