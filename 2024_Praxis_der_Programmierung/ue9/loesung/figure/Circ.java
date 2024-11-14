package figure;

public class Circ extends Square{
    private int radius;

    public Circ(){
        super();
        this.radius = 1;
    }

    public Circ(int initX, int initY){ 
        super(initX, initY);
        this.radius = 1;
    }

    public Circ(int initX, int initY, int initEdgeLen){ 
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
        return (2 * (int) Math.PI *  this.radius);  // pi durch 3 abgekürzt
    }

}
