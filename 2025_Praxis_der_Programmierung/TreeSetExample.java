import java.util.TreeSet;

public class TreeSetExample {
	public static void main(String[] args) {
		TreeSet<String> baume = new TreeSet<>();

		baume.add("Aal");
		baume.add("Tanne");
		baume.add("Birke");
		baume.add("Baum");

		for (String baum : baume) {
			System.out.println(baum);
		}
	}
}
