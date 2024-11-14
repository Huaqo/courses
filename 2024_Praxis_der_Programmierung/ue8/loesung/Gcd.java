
public class Gcd{


	 public static int gcd(int num, int denom){
		int x = num;
		int y = denom;

		// Sonderfall abfangen
		if (x == 0)
			return y;
		if (y == 0)
		 	return x;

		// Endlosschleife vermeiden
		if (x < 0)
		  x = -x;
		if (y < 0) 
		  y = -y;

		// Algorithmus von Euklid	 
		while (x != y) {
		  if (x > y)
			x = x - y;
		  else
			y = y - x;
		}
		return x;
	}


}
