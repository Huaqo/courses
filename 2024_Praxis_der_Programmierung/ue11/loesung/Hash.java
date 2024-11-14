
import java.util.*; //hashset, linked liste auch hier

public class Hash{
	
	
	public static void main(String args[]){
		Set<String> a = new HashSet<String>();
		a.add("Aal");
		a.add("Tanne");
		a.add("Birke");
		a.add("Baum");

		Iterator<String> iter = a.iterator();
		while (iter.hasNext()) {
			String s = iter.next();
			System.out.println(s);		
		}
	}
}


