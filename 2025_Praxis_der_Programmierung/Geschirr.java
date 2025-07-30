public abstract class Geschirr{
	protected int durchmesser;
	protected int hoehe;
	protected int gewicht;
	protected char function;

	public Geschirr(int durchmesser, int hoehe, int gewicht, char function){
		this.durchmesser = durchmesser;
		this.hoehe = hoehe;
		this.gewicht = gewicht;
		this.function = function;
	}

	public int getGewicht(){
		return gewicht;
	}

	public void setGewicht(int gewicht){
		this.gewicht = gewicht;
	}
}
