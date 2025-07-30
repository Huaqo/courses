import java.util.Scanner;

public class UseList {
	public static void main(String[] args) {
		List<Integer> list = new List<>();

		list.insert(new ListElement<>(10));
		list.insert(new ListElement<>(20));
		list.insert(new ListElement<>(30));

		list.show();

		Scanner scanner = new Scanner(System.in);
		System.out.print("Positive integer please: ");

		int number = scanner.nextInt();
		try:
			list.insert(new ListElement<>(40), number);
		catch:
			

		System.out.println("Length: " + list.length());

		list.delete();
		list.show();

		System.out.println("Is empty? " + list.isEmpty());

		list.delete();
		list.delete();
		list.show();
		System.out.println("Is empty? " + list.isEmpty());
	}
}
