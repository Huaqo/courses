import java.util.ArrayList;
import java.util.Collections;

public class PairComparableTest {
	public static void main(String[] args) {
		ArrayList<PairComparable<Integer, Integer>> pairs = new ArrayList<>();
		pairs.add(new PairComparable<>(5, 100));
		pairs.add(new PairComparable<>(2, 50));
		pairs.add(new PairComparable<>(8, 200));
		pairs.add(new PairComparable<>(3, 75));

		System.out.println("Vor dem Sortieren:");
		for (PairComparable<Integer, Integer> pair : pairs) {
			System.out.println(pair);
		}

		Collections.sort(pairs);

		System.out.println("\nNach dem Sortieren (nach erstem Element):");
		for (PairComparable<Integer, Integer> pair : pairs) {
			System.out.println(pair);
		}
	}
}
