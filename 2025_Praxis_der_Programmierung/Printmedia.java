public class Printmedia implements Readable {

	private int currentPage;
	protected int maxPage;

	public Printmedia(int currentPage, int maxPage) {
		this.currentPage = currentPage;
		this.maxPage = maxPage;
	}

	public int getCurrentPage() {
		return currentPage;
	}

	public int getMaxPage() {
		return maxPage;
	}

	@Override
	public void read(int amount) {
		if (currentPage + amount > maxPage) {
			throw new RuntimeException(
					"Cannot read because currentPage would exceed maxPage");
		}
		currentPage += amount;
	}
}
