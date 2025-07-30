"""Unit test suite for the `wgetdir` module."""
from urllib.parse import urljoin
from unittest import mock
from bs4 import BeautifulSoup
import wgetdir


def test_parse_urls():
    """Test that `parse_urls` correctly extracts valid file URLs from various HTML inputs."""
    html = '''
    <html>
      <body>
        <a href="https://example.com/file1.txt">File 1</a>
        <a href="https://example.com/folder/">Folder</a>
        <a href="/local/path/">Local Path</a>
        <a href="../">Parent</a>
        <a href="/">Root</a>
        <a href="https://example.com/file2.pdf">File 2</a>
      </body>
    </html>
    '''
    soup = BeautifulSoup(html, 'html.parser')
    soup_empty = BeautifulSoup("", 'html.parser')

    html_missing = '''
    <html><body>
      <a>Missing href</a>
      <a href="">Empty href</a>
    </body></html>
    '''
    soup_missing = BeautifulSoup(html_missing, 'html.parser')

    html_wrong_tag = '''
    <html><body>
      <div href="https://shouldnot.be.included">Wrong tag</div>
    </body></html>
    '''
    soup_wrong_tag = BeautifulSoup(html_wrong_tag, 'html.parser')

    result1 = wgetdir.parse_urls(soup)
    result2 = wgetdir.parse_urls(soup_empty)
    result3 = wgetdir.parse_urls(soup_missing)
    result4 = wgetdir.parse_urls(soup_wrong_tag)

    assert result1 == [
        "https://example.com/file1.txt",
        "https://example.com/file2.pdf"
    ]
    assert not result2
    assert result3 == [""]
    assert not result4


def test_wget(local_tmp_path):
    """Test that `wget` downloads a file from a URL."""
    url = "https://example.com/data.txt"
    expected_file = local_tmp_path / "data.txt"
    fake_content = "This is fake downloaded content."

    with mock.patch("wgetdir.checks.check_empty") as _, \
            mock.patch("wgetdir.checks.check_dir") as _, \
            mock.patch("wgetdir.utils.request_response") as mock_request:

        mock_response = mock.Mock()
        mock_response.text = fake_content
        mock_request.return_value = mock_response

        wgetdir.wget(url, str(local_tmp_path))

    assert expected_file.exists(), "File was not created"
    with expected_file.open("r") as f:
        content = f.read()
    assert content == fake_content, "File content does not match"


def test_wgetdir(local_tmp_path):
    """Test that `wgetdir` processes URL by retrieving all contained files."""
    directory_url = "https://example.com/data/"
    urls = ["file1.txt", "file2.pdf"]
    full_urls = [urljoin(directory_url, u) for u in urls]

    with mock.patch("wgetdir.logs.log_processing"), \
            mock.patch("wgetdir.logs.log_processed"), \
            mock.patch("wgetdir.checks.check_empty"), \
            mock.patch("wgetdir.checks.check_dir"), \
            mock.patch("wgetdir.utils.request_response") as mock_response, \
            mock.patch("wgetdir.utils.parse_html") as _, \
            mock.patch("wgetdir.parse_urls") as mock_parse_urls, \
            mock.patch("wgetdir.wget") as mock_wget:

        mock_parse_urls.return_value = urls
        mock_response.return_value = mock.Mock()

        wgetdir.wgetdir(directory_url, str(local_tmp_path))

        calls = [mock.call(url, str(local_tmp_path)) for url in full_urls]
        mock_wget.assert_has_calls(calls, any_order=False)
