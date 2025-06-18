package firstproblem;

public class Car extends Transport implements Maintainable{
    Car(int ID, String DriverName, int capacity) {
        super(ID, DriverName, capacity);
    }
    @Override
    public void performintenance(){
        System.out.println("Engine oil changed. Tire pressure checked.");
    }
}
