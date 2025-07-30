public class Geschirrschrank{
	private int kapazitaet;

	public Geschirrschrank(){
		this.kapazitaet = 0;
	}

	public Geschirrschrank(int kapazitaet){
		this.kapazitaet = kapazitaet;
	}

	public void einraeumen(Geschirr pGeschirr){	
        if (pGeschirr.getGewicht() <= kapazitaet) {
            kapazitaet -= pGeschirr.getGewicht();
            System.out.println("Geschirr eingeräumt. Verbleibende Kapazität: " + kapazitaet + " g");
        } else {
            System.out.println("Nicht genug Platz im Schrank!");
        }
	}
}
