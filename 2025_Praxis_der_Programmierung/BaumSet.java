import java.util.TreeSet;

public class BaumSet {

	public static void main(String[] args) {

		int n = 17;

		TreeSet<Integer> baumSet = new TreeSet<>();

		for (int i = 0; i < n; i++) {
			baumSet.add(i * 2);
		}

		for (Integer baum : baumSet) {
			System.out.println(baum);
		}

		int c = baumSet.higher(n);
		System.out.println(c);

		int d = baumSet.pollFirst();
		System.out.println(d);

	}
}
