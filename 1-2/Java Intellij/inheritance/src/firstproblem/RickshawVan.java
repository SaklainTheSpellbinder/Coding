package firstproblem;

public class RickshawVan extends Transport implements Maintainable {
    RickshawVan(int ID, String DriverName, int capacity) {
        super(ID, DriverName, capacity);
    }

    @Override
    public void performintenance(){
        System.out.println("Chains oiled. Brake pads inspected.");
    }
}
