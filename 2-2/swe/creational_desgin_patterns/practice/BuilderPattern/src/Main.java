

class Bicycle{
    String frame;
    String gearSystem;
    String tireType;
    public String getFrame() {
        return frame;
    }
    public void setFrame(String frame) {
        this.frame = frame;
    }
    public String getGearSystem() {
        return gearSystem;
    }
    public void setGearSystem(String gearSystem) {
        this.gearSystem = gearSystem;
    }
    public String getTireType() {
        return tireType;
    }
    public void setTireType(String tireType) {
        this.tireType = tireType;
    }

}

interface BiCycleBuilder{
    void buildFrame();
    void buildGearSystem();
    void buildTireType();

    Bicycle getBicycle();
}


class CommuterBuilder implements BiCycleBuilder{
    private final Bicycle bicycle= new Bicycle();

    @Override
    public void buildFrame(){
        bicycle.setFrame("Aluminum Frame");
    }

    @Override
    public void buildGearSystem(){
        bicycle.setGearSystem("Single Speed Gear");
    }

    @Override
    public void buildTireType(){
        bicycle.setTireType("Road Tires");
    }

    @Override
    public Bicycle getBicycle(){
        return bicycle;
    }

}


class MountainBuilder implements BiCycleBuilder{
    private final Bicycle bicycle= new Bicycle();

    @Override
    public void buildFrame(){
        bicycle.setFrame("Carbon Fiber Frame");
    }

    @Override
    public void buildGearSystem(){
        bicycle.setGearSystem("12-Speed Gear");
    }

    @Override
    public void buildTireType(){
        bicycle.setTireType("Off-road Grip Tires");
    }

    @Override
    public Bicycle getBicycle(){
        return bicycle;
    }

}


class Director{
    public Bicycle createBicycle(BiCycleBuilder builder){
        builder.buildFrame();
        builder.buildGearSystem();
        builder.buildTireType();
        return builder.getBicycle();
    }
}

public class Main {
    public static void main(String[] args) {
        Director dir=new Director();

        Bicycle commuter= dir.createBicycle(new CommuterBuilder());

        Bicycle mountain= dir.createBicycle(new MountainBuilder());

        

    }
}