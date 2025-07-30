class Rational{

	private int num;
	private int denom;

	public Rational(){	
		this.num = 0;
		this.denom = 1;
	}

	public Rational(int num){
		this.num = num;
		this.denom = 1;
	}

	public Rational(int num, int denom){
		this.num = num;
		this.denom = denom;
	}


	public void reduce(){
		int gcd = Gcd.gcd(this.num, this.denom);
		this.num = this.num / gcd;
		this.denom = this.denom / gcd;
	}

	public void extent(int extent){
		this.num = this.num * extent;
		this.denom = this.denom * extent;
	}

	public String toString(){
		return this.num + "/" + this.denom;
	}

	public String toStringReduced(){
		reduce();
		return toString();
	}

	public Rational mult(Rational number){
		Rational r = new Rational();
		r.num = this.num * number.num;
		r.denom = this.denom * number.denom;
		r.reduce();
		return r;
	}

	public static void main(String[] args){
		Rational rat = new Rational(12, 24);
		System.out.println(rat.toString());
		System.out.println(rat.toStringReduced());
		rat.extent(12);
		System.out.println(rat.toString());
	}
}
