import java.util.LinkedList;
import java.util.Collections;

public class Zug {
	private String name;
	private LinkedList<Zugteil> zugteile;

	public Zug(Lokomotive lok) {
		zugteile = new LinkedList<>();
		zugteile.add(lok);
	}

	public void addWagen(Wagen wagen) {
		Zugteil firstteil = zugteile.getFirst();
		if (firstteil instanceof Lokomotive) {

			Lokomotive lok = (Lokomotive) firstteil;
			if (lok.getMaxWaggons() > this.getNumberOfWaggons()) {
				zugteile.add(wagen);
			} else {
				throw new IllegalStateException("max Wagen fuer lok erreicht.");
			}
		}
	}

	public void addWagen(Wagen wagen, int i) {

		if (i <= 0) {
			throw new IllegalArgumentException("Wagen dürfen nicht vor der Lokomotive eingefügt werden.");
		}
		zugteile.add(i, wagen);
	}

	public void print() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < zugteile.size(); i++) {
			sb.append(zugteile.get(i).toString());
			if (i < zugteile.size() - 1) {
				sb.append(" - ");
			}
		}
		System.out.println(sb.toString());
	}

	public int getNumberOfWaggons() {
		int numWaggons = 0;
		for (Zugteil zugteil : zugteile) {
			if (zugteil instanceof Wagen) {
				numWaggons++;
			}
		}
		return numWaggons;
	}

	public int getPassengers() {
		int cap = 0;
		for (Zugteil zugteil : zugteile) {
			if (zugteil instanceof Wagen) {
				Wagen wagen = (Wagen) zugteil;
				cap += wagen.getCap();
			}
		}
		return cap;
	}

	public int getLength() {
		int laength = 0;
		for (Zugteil zugteil : zugteile) {
			laength += zugteil.getLaenge();
		}
		return laength;
	}

	public void changeLoc(Lokomotive lok) {
		if (zugteile.getFirst() instanceof Lokomotive) {
			zugteile.removeFirst();
		}
		zugteile.addFirst(lok);
	}

	public Wagen removeCar(int i) {
		if (zugteile.get(i) instanceof Wagen) {
			return (Wagen) zugteile.remove(i);
		}
		return null;
	}

	public void relink(Zug other) {
		if (this == other) {
			throw new IllegalArgumentException("Ein Zug kann nicht an sich selbst angehängt werden.");
		}

		LinkedList<Wagen> wagonsToMove = new LinkedList<>();
		for (int i = 1; i < other.zugteile.size(); i++) {
			Zugteil zt = other.zugteile.get(i);
			if (zt instanceof Wagen) {
				wagonsToMove.add((Wagen) zt);
			}
		}

		for (Wagen w : wagonsToMove) {
			other.zugteile.remove(w);
		}

		for (Wagen w : wagonsToMove) {
			this.addWagen(w);
		}
	}

	public void revert() {
		if (zugteile.isEmpty() || zugteile.size() <= 1) {
			return;
		}

		Zugteil lok = zugteile.get(0);

		LinkedList<Zugteil> wagons = new LinkedList<>(zugteile.subList(1, zugteile.size()));
		java.util.Collections.reverse(wagons);

		zugteile.clear();
		zugteile.add(lok);
		zugteile.addAll(wagons);
	}

}
