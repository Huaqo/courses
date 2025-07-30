"""
This script downloads all files from a given online directory URL and saves them
to a specified local directory.

It parses the provided URL for downloadable files (ignores subdirectories) and writes
the content of each file into the output directory.

Usage:
    python wgetdir.py <directory_url> <directory_path>

Arguments:
    directory_url (str or Path):   URL to an online directory.
    directory_path (str or Path):  Path to a local directory where files will be saved.
"""

import sys
import os
from urllib.parse import urljoin
import utils
import checks
import logs


def parse_urls(html):
    '''
    Fetches all valid URLs from anchor tags in an HTML document.

    Arguments:
        html (BeautifulSoup): The parsed HTML using BeautifulSoup.

    Returns:
        List[str]: A list of URLs (hrefs) found in the HTML.
    '''
    urls = []
    for anchor in html.find_all('a', href=True):
        href = anchor['href']
        if href in ('../', '/'):
            continue
        if href.endswith('/'):
            continue
        urls.append(href)

    return urls


def wget(url, dir_path):
    """
    Download a file form a URL and saves it to a local directory.

    Arguments:
        url (str):      The URL of the online file.
        dir_path (str): The local directory path where the file will be saved.

    Returns:
        None: The downloaded content is written to a file in `dir_path`.
    """
    checks.check_empty(url)
    checks.check_dir(dir_path)
    name = url.split('/')[-1]
    path = os.path.join(dir_path, name)
    content = utils.request_response(url)
    utils.save_file(content.text, path)


def wgetdir(directory_url, directory_path):
    """
    Downloads all files from an online directory URL and saves them into a local directory.

    Arguments:
        directory_url (str):    The URL of the online directory containing files.
        directory_path (str):   The local directory path where files will be saved.

    Returns:
        None: All downloadable files in the directory are saved to `directory_path`.
    """
    logs.log_processing(os.path.basename(__file__))
    logs.log_parameter("directory_url", str(directory_url))
    checks.check_empty(directory_url)
    checks.check_dir(directory_path)
    os.makedirs(directory_path, exist_ok=True)

    response = utils.request_response(directory_url)
    html = utils.parse_html(response)

    urls = parse_urls(html)

    for url in urls:
        url = urljoin(directory_url, url)
        wget(url, directory_path)

    logs.log_processed(os.path.basename(__file__))


if __name__ == "__main__":
    checks.check_args(3, __doc__)
    wgetdir(sys.argv[1], sys.argv[2])
