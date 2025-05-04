abstract class Figure {
    double dim1,dim2;
    Figure(double a,double b){
        dim1=a;
        dim2=b;
    }


    abstract double area();
    void show(){
        System.out.println("Abstract");
    }
}
