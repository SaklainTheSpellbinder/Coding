public class Rectangle extends Figure{
    Rectangle(double a,double b){
            super(a,b);
    }
    double area(){
        return dim1*dim2;
    }
    void show(){
        System.out.println("Rectangle Area: " + area());
    }
}
