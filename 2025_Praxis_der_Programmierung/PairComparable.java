public class PairComparable<X extends Number & Comparable<X>, Y extends Number>
		implements Comparable<PairComparable<X, Y>> {

	private X first;
	private Y second;

	public PairComparable(X first, Y second) {
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
	public int compareTo(PairComparable<X, Y> other) {
		double thisFraction = this.first.doubleValue() / this.second.doubleValue();
		double otherFraction = other.first.doubleValue() / other.second.doubleValue();

		return Double.compare(thisFraction, otherFraction);
	}

	@Override
	public String toString() {
		return "(" + first + ", " + second + ")";
	}

}
