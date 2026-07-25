package slideA;

public class Car implements IBuilder {
    private final Product product=new Product();

    @Override
    public void buildBody() {
        product.add("This is the body of a Car.");
    }

    @Override
    public void insertWHeels() {
        product.add("4 wheels are added");
    }

    @Override
    public void addHeadLights() {
        product.add("2 headlights are added");
    }

    @Override
    public Product getVehicle() {
        return product;
    }
}


class MotorCycle implements IBuilder{
    private final Product product =new Product();

    @Override
    public void buildBody() {
        product.add("This is the body of a MotorCycle");
    }

    @Override
    public void insertWHeels() {
        product.add("2 wheels are added");
    }

    @Override
    public void addHeadLights() {
        product.add("1 headlight is added");
    }

    @Override
    public Product getVehicle() {
        return product;
    }
}
