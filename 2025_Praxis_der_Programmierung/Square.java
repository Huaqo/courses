package figure;

public class Square extends Figure {

	private int edgeLength;

	public Square() {
		super(0, 0);
		this.edgeLength = 0;
	}

	public Square(int edgeLength) {
		super(0, 0);
		this.edgeLength = edgeLength;
	}

	public Square(int x, int y, int edgeLength) {
		super(x, y);
		this.edgeLength = edgeLength;
	}

	public Square(Square other) {
		String[] pos = other.getPos().split(",");
		int x = Integer.parseInt(pos[0].trim());
		int y = Integer.parseInt(pos[1].trim());
		super.moveTo(x, y);
		this.edgeLength = other.getSize();
	}

	@Override
	public int getSize() {
		return edgeLength;
	}

	@Override
	public void setSize(int edgeLength) {
		this.edgeLength = edgeLength;
	}

	@Override
	public double getArea() {
		return edgeLength * edgeLength;
	}

	@Override
	public double getPerimeter() {
		return edgeLength * 4;
	}

	public void show() {
		System.out.println(
				"Pos:" + this.getPos() + "edgeLength: " + this.getSize());
	}

}
