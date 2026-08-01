package Bridge;

interface Color{
    void applyColor();
}

class Red implements Color{
    @Override
    public void applyColor() {
        System.out.println("Applying the color Red.");
    }
}

class Blue implements Color{
    @Override
    public void applyColor() {
        System.out.println("Applying the color Blue.");
    }
}

abstract class Shape{
    protected Color color;

    public Shape(Color color){
        this.color=color;
    }

    public abstract void draw();
}

class Circle extends Shape{
    public Circle(Color color){
        super(color);
    }

    @Override
    public void draw() {
        System.out.println("Drawing a Circle...");
        color.applyColor();
    }
}

class Square extends Shape{
    public Square(Color color){
        super(color);
    }

    @Override
    public void draw() {
        System.out.println("Drawing a Square...");
        color.applyColor();
    }
}

public class DrawingApp {
    public static void main(String[] args){
        Color red=new Red();
        Color blue=new Blue();

        Shape redCircle=new Circle(red);
        Shape blueSquare=new Square(blue);

        redCircle.draw();
        blueSquare.draw();
    }
}
