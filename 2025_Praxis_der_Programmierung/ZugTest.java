public class ZugTest {
	public static void main(String[] args) {
		// 1. Lokomotive „Big Chief“ mit Typ-ID 5311 und Länge 23m
		Lokomotive bigChief = new Lokomotive(23, true, 5311, "Big Chief", 10); // maxWaggons auf 10 gesetzt

		// 2. Zug „Santa Fe“ mit Lok „Big Chief“
		Zug santaFe = new Zug(bigChief);

		// 3. Drei Wagen an „Santa Fe“ anhängen
		santaFe.addWagen(new Wagen(12, true, 50));
		santaFe.addWagen(new Wagen(15, true, 75));
		santaFe.addWagen(new Wagen(20, true, 100));

		// 4. Lokomotive „Steel Horse“ mit Typ-ID 5409 und Länge 21m
		Lokomotive steelHorse = new Lokomotive(21, true, 5409, "Steel Horse", 10);

		// 5. Zug „Rio Grande Express“ mit Lok „Steel Horse“
		Zug rioGrandeExpress = new Zug(steelHorse);

		// 6. Zwei Wagen an „Rio Grande Express“ anhängen
		rioGrandeExpress.addWagen(new Wagen(13, true, 60));
		rioGrandeExpress.addWagen(new Wagen(18, true, 80));

		// Ausgabe vor dem Übertragen der Wagen
		System.out.println("Vor dem Übertragen:");
		System.out.print("Santa Fe: ");
		santaFe.print();
		System.out.print("Rio Grande Express: ");
		rioGrandeExpress.print();

		// 7. Alle Wagen von „Santa Fe“ zu „Rio Grande Express“ übergeben
		rioGrandeExpress.relink(santaFe);

		// Ausgabe nach dem Übertragen
		System.out.println("\nNach dem Übertragen:");
		System.out.print("Santa Fe: ");
		santaFe.print();
		System.out.print("Rio Grande Express: ");
		rioGrandeExpress.print();

	}
}
