public class Triangle extends Figure{
    Triangle(double a,double b){
        super(a,b);
    }
    double area(){
        return 0.5*dim1*dim2;
    }
    void show(){
        System.out.println("Triangle Area: " + area());
    }
}
