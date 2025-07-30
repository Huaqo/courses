
/** Bindung.java
 * 
 * Eine Klasse, die am Beispiel des figure-Pakets
 * statische und dynamische Typen ausprobiert
 */

import figure.*;

class Bindung {

	public static void main(String[] args) {

		Figure f = new Square(1);
		f.moveTo(2, 3);
		f.getArea();
		// f.show();

		if (f instanceof Square) {
			((Square) f).show(); // analog: (double)17
		}

		System.out.println("Flaecheninhalt: " + f.getArea());
		f = new Circle(10);
		System.out.println("Flaecheninhalt: " + f.getArea());

	}
}

// Bindung
