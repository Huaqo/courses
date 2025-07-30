import java.util.HashSet;

public class BaumHashSet {
	public static void main(String[] args) {
		int n = 17;

		HashSet<Integer> baumSet = new HashSet<>();

		for (int i = 0; i < n; i++) {
			baumSet.add(i * 2);
		}

		for (Integer value : baumSet) {
			System.out.println(value);
		}

		Integer smallestGreater = null;

		for (Integer value : baumSet) {
			if (value > n) {
				if (smallestGreater == null || value < smallestGreater) {
					smallestGreater = value;
				}
			}
		}

		if (smallestGreater != null) {
			System.out.println("Smallest element > " + n + ": " + smallestGreater);
		} else {
			System.out.println("No element greater than " + n);
		}

		Integer smallest = null;
		for (Integer value : baumSet) {
			if (smallest == null || value < smallest) {
				smallest = value;
			}
		}

		if (smallest != null) {
			System.out.println("Smallest element: " + smallest);
			baumSet.remove(smallest); // Remove it
		} else {
			System.out.println("Set is empty");
		}

		System.out.println("Set after removal: " + baumSet);

	}
}
