public class Lokomotive extends Zugteil {
	private int id;
	private String name;
	private int maxWaggons;

	public Lokomotive(int laenge, boolean status, int id, String name, int maxWaggons) {
		super(laenge, status);
		this.id = id;
		this.name = name;
		this.maxWaggons = maxWaggons;
	}

	public int getMaxWaggons() {
		return maxWaggons;
	}

	@Override
	public String toString() {
		return "<" + id + ", " + name + ", " + getLaenge() + ">";
	}
}
