/**
* Point.class
*
*/

public class Point{
	int x, y;

	Point(){
		this.x = 0;
		this.y = 0;
	}
	
	Point(int x, int y){
		this.x = x;
		this.y = y;
	}
	
	
	void moveTo(int new_x, int new_y){
		this.x = new_x;
		this.y = new_y;
	}

	int getX(){
		return this.x;
	}

	int getY(){
		return this.y;
	}

}
