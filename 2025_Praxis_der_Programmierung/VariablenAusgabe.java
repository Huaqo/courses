/** VariablenAusgabe.java
 *
 *  Ein Programm, das die Vereinbarung sowie 
 *  die Ausgabe von Variablen einfacher Datentypen
 *  demonstriert.
 */


class VariablenAusgabe {

  public static void main (String[] args) {

    int num1 = 12;
    int num2 = -4;

    System.out.println(num1);
    System.out.println(num2);
    System.out.println();

    System.out.println(5);
    System.out.println(5 + num2);
    System.out.println();

    System.out.print(5);
    System.out.println(num2);

    System.out.println(num1 + " " + num2);

	System.out.println("Wert von num1: " + num1);

	String string = "Hello World!";
	string = string.concat(" From Joaquin.");
	string = string.replace('e', 'a');
	string = string.toLowerCase();
	string = string.toUpperCase();
	System.out.println(string);	

	String[] split = string.split("! ", 2);
	System.out.println(split[0]);
	System.out.println(split[1]);


	boolean stringsAreEqual = split[0].equals(split[1]);
	System.out.println(stringsAreEqual);
  }
}

// VariablenAusgabe
