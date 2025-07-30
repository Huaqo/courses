import figure.Square;
import figure.Circle;

public class Main {
	public static void main(String[] args) {
		Square square = new Square(0, 0, 10);
		System.out.println(square.getSize());
		square.setSize(20);
		System.out.println(square.getSize());
		System.out.println(square.getArea());
		System.out.println(square.getPerimeter());
		System.out.println(square.getPos());
		square.moveTo(1, 1);
		System.out.println(square.getPos());
		square.moveBy(1, 1);
		System.out.println(square.getPos());

		Circle circle = new Circle(0, 0, 10);
		System.out.println(circle.getSize());
		circle.setSize(20);
		System.out.println(circle.getSize());
		System.out.println(circle.getArea());
		System.out.println(circle.getPerimeter());
		System.out.println(circle.getPos());
		circle.moveTo(1, 1);
		System.out.println(circle.getPos());
		circle.moveBy(1, 1);
		System.out.println(circle.getPos());

		// ue10
		System.out.println("\nue10\n");

		Square square1 = new Square(1, 2, 3);

		square1.show();
		System.out.println(square1);

		Square square2 = new Square(square1);
		square2.show();
		System.out.println(square2);
		square2.moveTo(99, 99);
		square2.setSize(42);

		square1.show();
		square2.show();
	}
}
