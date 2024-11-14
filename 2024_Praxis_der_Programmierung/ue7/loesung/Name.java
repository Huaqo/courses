
/**
 * Name.java
 * 
 * Programmfragment, das Tastatureingaben ermoeglicht 
 *
 */

import java.util.Scanner;

class Name {
	//String vorname, nachname;
	//int alter;
	

  public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Gebe deinen Vornamen ein: ");
		String vorname = scanner.next();
		
		System.out.print("Gebe deinen Nachnamen ein: ");
		String nachname = scanner.next();
		
		System.out.print("Gebe dein ALter ein: ");
		int alter = scanner.nextInt();
	
		System.out.println(""+ vorname + " " + nachname);
		System.out.println("Ihr Vorname hat "+ vorname.length()+ " Buchstaben");
		System.out.println("" + vorname.charAt(0) + ". " + nachname.charAt(0) + ".");
		System.out.println("Sie sind " + alter + " Jahre alt");
		
    // Methoden für weitere Datentypen existieren
    // siehe API

  }

}

// Vorlage
