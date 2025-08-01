package figure;

public class Point {
	private int x;
	private int y;

	public Point() {
	}

	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	public void moveTo(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public void moveBy(int x, int y) {
		this.x += x;
		this.y += y;
	}

	public String toString() {
		return this.x + ", " + this.y;
	}

}
