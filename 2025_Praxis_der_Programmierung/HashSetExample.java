import java.util.HashSet;

public class HashSetExample {
	public static void main(String[] args) {
		HashSet<String> baume = new HashSet<>();

		baume.add("Aal");
		baume.add("Tanne");
		baume.add("Birke");
		baume.add("Baum");

		for (String baum : baume) {
			System.out.println(baum);
		}
	}
}
