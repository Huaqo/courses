


public class Verdeckung{

	void display(int n) {
	  int m = 11;
	  System.out.println(String.format("A1: m = %d, n = %d", m, n));
	}
		    

	public static void main(String[] args) {
	  Verdeckung v = new Verdeckung();
	  int a = 12;
	  int m = 1;
	  int n = 2;
	  v.display(a);
		         
	  if (m == 1) {
		int x = 22;
		System.out.println(String.format("A2: m = %d, n = %d", m, x));
	  }
	  System.out.println(String.format("A3: m = %d, n = %d", m, n));
	}

}
