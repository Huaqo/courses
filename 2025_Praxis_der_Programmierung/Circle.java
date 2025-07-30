package figure;

public class Circle extends Figure {

	private int radius;

	public Circle() {
		super(0, 0);
		this.radius = 0;
	}

	public Circle(int radius) {
		super(0, 0);
		this.radius = radius;
	}

	public Circle(int x, int y, int radius) {
		super(x, y);
		this.radius = radius;
	}

	@Override
	public int getSize() {
		return radius;
	}

	@Override
	public void setSize(int radius) {
		this.radius = radius;
	}

	@Override
	public double getArea() {
		return 3.14 * radius * radius;
	}

	@Override
	public double getPerimeter() {
		return 2 * 3.14 * radius;
	}
}
