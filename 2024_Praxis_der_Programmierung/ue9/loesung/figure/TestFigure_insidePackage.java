
package figure;

public class TestFigure{

    public static void main(String[] args){
        Square square = new Square(1,1,5); // links größer oder gleich (Hierachie)
        System.out.println(square.getArea());
	square.show();
	Square squareCopy = new Square(square);
	squareCopy.show();
	//System.out.println(square == squareCopy);
	//System.out.println(square.equals(squareCopy));
	
	System.out.println(""+ square.toString() + "  "+squareCopy.toString());
	System.out.println("toString: " + square.toString() == squareCopy.toString());
	
	squareCopy.setSize(10);
	squareCopy.show();

        Circle circle = new Circle(4,5,3);
        System.out.println(circle.getX());
        System.out.println(circle.getArea());
        Circ circ = new Circ(4,5,3);
        System.out.println(circ.getX());
        System.out.println(circ.getArea());

        /* 
        *  statischer Dynamischer Type? // links größer oder gleich (Hierachie)
        */
    }
}
