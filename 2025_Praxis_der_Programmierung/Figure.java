package figure;

public abstract class Figure {
	private Point pos;

	// only visible to subclasses

	protected Figure() {
		this.pos = new Point();
	}

	protected Figure(int x, int y) {
		this.pos = new Point(x, y);
	}

	// public methods

	public String getPos() {
		return this.pos.toString();
	}

	public void moveTo(int x, int y) {
		this.pos.moveTo(x, y);
	}

	public void moveBy(int x, int y) {
		this.pos.moveBy(x, y);
	}

	// abstract methods

	public abstract int getSize();

	public abstract void setSize(int size);

	public abstract double getArea();

	public abstract double getPerimeter();
}
