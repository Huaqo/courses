

public class Rational{
	private int num, denom;

	Rational(){
		this.num = 0;
		this.denom = 1;
	}

	Rational(int num){
		this.num = num;
		this.denom = 1;
	}

	Rational(int num, int denom){
		this.num = num;
		this.denom = denom;
	}

	/*
	int gcd(){
		int x = this.num;
		int y = this.denom;

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
*/

	void reduce(){
		//int gcd = gcd();
		Gcd gcd_object = new Gcd();
		int gcd = gcd_object.gcd(this.num, this.denom);   
		this.num = this.num / gcd;
		this.denom = this.denom /gcd;
	}


	void extend(int fac){
		this.num *= fac;
		this.denom *= fac;	
	}


	public String toString(){
		String str = this.num + "/" + this.denom;
		return str;
	}


	String toStringReduced(){
		reduce();
		String str = this.num + "/" + this.denom;
		return str;
	}

	
	Rational mult(Rational rat){
		Rational mult_rat = new Rational();
		mult_rat.num = this.num * rat.num;
		mult_rat.denom = this.denom * rat.denom;
		mult_rat.reduce();
		return mult_rat;
	}
	

	







}
