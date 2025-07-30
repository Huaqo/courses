public class Wagen extends Zugteil {
	private int kapazitaet;

	public Wagen(int laenge, boolean status, int kapazitaet) {
		super(laenge, status);
		this.kapazitaet = kapazitaet;
	}

	public int getCap() {
		return kapazitaet;
	}

	@Override
	public String toString() {
		return "[" + kapazitaet + ", " + getLaenge() + "]";
	}
}
