package figure;

public abstract class Figure{
    private Point point;

    protected Figure(){
        point = new Point();
    }

    protected Figure(int initX, int initY){
        point = new Point(initX, initY);
    }


    public void moveTo(int new_x, int new_y){
		this.point.moveTo(new_x, new_y); 
	}

	public int getX(){
		return this.point.getX();
	}

	public int getY(){
		return this.point.getY();
	}

    abstract public int getSize();
    abstract public void setSize(int newSize);
    abstract public int getArea();
    abstract public int getUmfang();
}
