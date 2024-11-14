

public class TestPairComp{


	public static void main (String args[]){
		PairComp<Integer, Integer> p1 = new PairComp<Integer, Integer>(6,2);
		System.out.println(p1.getFirst());
		System.out.println(p1.getSecond());

		PairComp<Integer, Integer> p2 = new PairComp<Integer, Integer>(2,3);
		System.out.println(p2.getFirst());
		System.out.println(p2.getSecond());

		System.out.println(p1.compareTo(p2));
	}

}
