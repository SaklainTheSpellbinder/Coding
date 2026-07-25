package slideA;

public class BuilderPatternDemo {
    public static void main(String[] args){
        System.out.println("hehe builder pattern here:");

        Director director =new Director();

        IBuilder carBuilder=new Car();
        IBuilder motorbuilder=new MotorCycle();

        director.construct(carBuilder);
        Product p1=carBuilder.getVehicle();
        p1.show();

        director.construct(motorbuilder);
        Product p2=motorbuilder.getVehicle();
        p2.show();
    }
}
