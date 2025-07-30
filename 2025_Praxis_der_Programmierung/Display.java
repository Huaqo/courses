public class Display {

	static void display(int n) {
		int m = 11;
		System.out.printf("A1: m = %d, n = %d\n", m, n);
	}

	public static void main(String[] args) {

		int a = 12;
		int m = 1;
		int n = 2;
		display(a);

		if (m == 1) {
			int n2 = 22;
			System.out.printf("A2: m = %d, n = %d\n", m, n2);
		}

		System.out.printf("A3: m = %d, n = %d\n", m, n);
	}
}
