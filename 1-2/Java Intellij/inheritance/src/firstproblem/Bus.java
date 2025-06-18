package firstproblem;

public class Bus extends Transport implements Maintainable{
    Bus(int ID,String DriverName, int capacity){
        super(ID,DriverName,capacity);
    }

    @Override
    public void performintenance() {
        System.out.println("Engine checked. Air filter replaced. Seat belts inspected.");
    }
}
