public class Pair<X extends Number, Y extends Number> {

	private X first;
	private Y second;

	public Pair(X first, Y second) {
		this.first = first;
		this.second = second;
	}

	public X getFirst() {
		return first;
	}

	public void setFirst(X first) {
		this.first = first;
	}

	public Y getSecond() {
		return second;
	}

	public void setSecond(Y second) {
		this.second = second;
	}

	@Override
	public String toString() {
		return "(" + first + ", " + second + ")";
	}

}
