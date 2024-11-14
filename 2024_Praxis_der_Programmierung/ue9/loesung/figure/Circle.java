package figure;

public class Circle extends Figure{
    private int radius;

    public Circle(){
        super();
        this.radius = 1;
    }

	public Circle(int initEdgeLen){ 
        super();
        this.radius = initEdgeLen;
    }


    public Circle(int initX, int initY){ 
        super(initX, initY);
        this.radius = 1;
    }

    public Circle(int initX, int initY, int initEdgeLen){ 
        super(initX, initY);
        this.radius = initEdgeLen;
    }

    public int getSize(){  // Größe von Kreis? was gemeint?
        return this.radius;
    }

    public void setSize(int newRadius){
        this.radius = newRadius;
    }

    public int getArea(){
        return this.radius* this.radius * 3 ; // 3 für pi
    }

    public int getUmfang(){
        return (2 * 3*  this.radius);  // pi durch 3 abgekürzt
    }

}
