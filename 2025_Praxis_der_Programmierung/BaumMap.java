import java.util.TreeMap;

public class BaumMap {

	public static void main(String[] args) {

		int n = 17;

		TreeMap<Integer, Integer> baumMap = new TreeMap<>();

		for (int i = 0; i < n; i++) {
			baumMap.put(i, i * 2);
		}

		for (Integer value : baumMap.values()) {
			System.out.println(value);
		}

		Integer c = null;
		for (Integer value : baumMap.values()) {
			if (value > n) {
				c = value;
				System.out.println(c);
				break;
			}
		}

		var d = baumMap.pollFirstEntry();
		System.out.println(d.getValue());

	}
}
