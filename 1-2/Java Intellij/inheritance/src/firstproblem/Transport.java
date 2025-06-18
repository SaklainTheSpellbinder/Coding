package firstproblem;

public class Transport {
    private int ID;
    private String DriverName;
    private int capacity;
    Transport(int ID, String DriverName, int capacity) {
        this.ID = ID;
        this.DriverName = DriverName;
        this.capacity = capacity;
    }
    public int getID(){
        return ID;
    }

    public String getDriverName(){
        return DriverName;
    }

    public int getCapacity(){
        return capacity;
    }
}
