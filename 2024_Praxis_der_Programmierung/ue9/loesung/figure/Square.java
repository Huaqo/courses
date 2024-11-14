package figure;

public class Square extends Figure{
    private int size;

    public Square(){
        super();
        this.size = 1;
    }

    public Square(int initX, int initY){ 
        super(initX, initY);
        this.size = 1;
    }

    public Square(int initX, int initY, int initEdgeLen){ 
        super(initX, initY);
        this.size = initEdgeLen;
    }

	
	public Square(Square original){
		super(original.getX(), original.getY());
        this.size = original.size;
	}


    public int getSize(){
        return this.size;
    }

    public void setSize(int newSize){
        this.size = newSize;
    }

    public int getArea(){
        return this.size* this.size;
    }

    public int getUmfang(){
        return (4 * this.size);
    }

	public void show(){
		System.out.println("Size: "+ this.size + ", Area: " + this.getArea() + ", Umfang: " + this.getUmfang());
		return;
	}
}
