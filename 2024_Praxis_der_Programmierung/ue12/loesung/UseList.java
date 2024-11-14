
import java.util.*;


public class UseList {

	public static void main(String [] args){
		ListElement<Integer> le1 = new ListElement<Integer>(10, null);
		List<Integer> list = new List<Integer>(le1);
		ListElement<Integer> le2 = new ListElement<Integer>(20, null);
		ListElement<Integer> le3 = new ListElement<Integer>(30, null);
		ListElement<Integer> le4 = new ListElement<Integer>(40, null);

		list.insert(le2);
		list.insert(le3);

		list.show();

		//System.out.println("Laenge: " + list.length());
		//list.delete();
		//list.show();
		
		//list.insertIndex(le4, 1);
		//list.show();
		
		Scanner scan = new Scanner(System.in);

		while(true){
			try{
				System.out.print("Gebe eine positive Zahl ein: ");
				int index = Integer.parseInt(scan.next());
				list.insertIndex(le4, index);
				list.show();
				break;
			}
			
			catch(NumberFormatException e){
				System.err.println("Keine ganze Zahl eingegeben!");
				continue;
			}

			catch(InputMismatchException e){
				//bei parser nutzen
				System.err.println("Keine ganze Zahl eingegeben!");
				continue;
			}

			catch(NullPointerException e){
				System.err.println("index blöd sein");
				continue;
			}
		}
	}
}
