package Decorator;

interface Coffee {
    String getDescription();
    Double getCost();
}

class SimpleCoffee implements Coffee{
    @Override
    public String getDescription() {
        return "Simple Coffee";
    }

    @Override
    public Double getCost() {
        return 2.00;
    }
}

abstract class CoffeeDecorator implements Coffee{
    protected Coffee wrappedCoffee;
    public CoffeeDecorator(Coffee wrappedCoffee){
        this.wrappedCoffee=wrappedCoffee;
    }

    @Override
    public String getDescription() {
        return wrappedCoffee.getDescription();
    }

    @Override
    public Double getCost() {
        return wrappedCoffee.getCost();
    }
}

class MilkDecorator extends CoffeeDecorator{
    public MilkDecorator(Coffee wrapped){
        super(wrapped);
    }

    @Override
    public String getDescription() {
        return super.getDescription()+", Milk";
    }

    @Override
    public Double getCost() {
        return super.getCost()+0.50;
    }
}


class MochaDecorator extends CoffeeDecorator{
    public MochaDecorator(Coffee coffee){
        super(coffee);
    }

    @Override
    public String getDescription() {
        return super.getDescription()+", Mocha";
    }

    @Override
    public Double getCost() {
        return super.getCost()+ 0.75;
    }
}

public class CoffeeShope{
    public static void main(String[] args){
        Coffee myorder=new SimpleCoffee();

        myorder=new MilkDecorator(myorder);
        myorder=new MochaDecorator(myorder);

        System.out.println("Order: "+ myorder.getDescription());
        System.out.println("Total Cost: $"+myorder.getCost());
    }
}
