interface Shape {
    void draw();
}

class Circle implements Shape {
    @Override
    public void draw() {
        System.out.println("Drawing Circle");
    }
}

class Square implements Shape {
    @Override
    public void draw() {
        System.out.println("Drawing Square");
    }
}


public class PolymorphismUsingInterface {
    public static void main(String[] args){
        Shape s;
        s = new Circle();
        s.draw();

        s = new Square();
        s.draw();
        

        System.out.printf("%d %d\n",100,200);
          
    }
}
