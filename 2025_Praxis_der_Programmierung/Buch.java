public class Buch extends Printmedia {

	public Buch(int currentPage, int maxPage) {
		super(currentPage, maxPage);
	}

	public static void main(String[] args) {
		Buch lotr1 = new Buch(0, 448);
		try {
			lotr1.read(500);
		} catch (RuntimeException e) {
			System.out.println("Fehler beim lesen: " + e.getMessage());
		}

		System.out.println("Aktuelle Seiten nach dem Leseversuch: " + lotr1.getCurrentPage());

		try {
			lotr1.read(100);
		} catch (RuntimeException e) {
			System.out.println("Fehler beim lesen: " + e.getMessage());
		}

		System.out.println("Aktuelle Seiten nach dem Leseversuch: " + lotr1.getCurrentPage());
		lotr1.maxPage = 531;
		System.out.println("Aktuelle Seiten nach dem Leseversuch: " + lotr1.getMaxPage());
	}
}
