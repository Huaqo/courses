/**
* Point.class
*
*/
package figure;

public class Point{
	private int x, y;

	Point(){
		this.x = 0;
		this.y = 0;
	}
	
	Point(int x, int y){
		this.x = x;
		this.y = y;
	}
	
	public void moveTo(int new_x, int new_y){
		this.x = new_x;
		this.y = new_y;
	}

	public int getX(){
		return this.x;
	}

	public int getY(){
		return this.y;
	}

}
