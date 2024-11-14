

public class TestPair{


	public static void main (String args[]){
		Pair<Integer, Integer> p = new Pair<Integer, Integer>(6,2);
		System.out.println(p.getFirst());
		System.out.println(p.getSecond());

		Pair<Double, Integer> p2 = new Pair<Double, Integer>(6.0,2);
		System.out.println(p2.getFirst());
		System.out.println(p2.getSecond());
	}

}
