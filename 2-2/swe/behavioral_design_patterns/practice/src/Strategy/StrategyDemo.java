package Strategy;
import java.util.Objects;


//strategy interfaces

interface FlyBehavior{
    void fly();
}

interface QuackBehavior{
    void quack();
}


//Concrete flying strategies

class FlyWithWings implements FlyBehavior{
    @Override
    public void fly() {
        System.out.println("Flying with wings");
    }
}

class FlyNoWay implements FlyBehavior{
    @Override
    public void fly() {
        System.out.println("Cannot fly");
    }
}

class FlyRocketPowered implements FlyBehavior{
    @Override
    public void fly() {
        System.out.println("Flying with a rocket");
    }
}


//concrete quacking strategies

class NormalQuack implements QuackBehavior{
    @Override
    public void quack() {
        System.out.println("Quack");
    }
}

class Squeak implements QuackBehavior{
    @Override
    public void quack() {
        System.out.println("Squeak");
    }
}

class MuteQuack implements QuackBehavior{
    @Override
    public void quack() {
        System.out.println("Silence");
    }
}

// context

abstract class Duck{
    private FlyBehavior flyBehavior;
    private QuackBehavior quackBehavior;

    protected Duck(FlyBehavior flyBehavior,QuackBehavior quackBehavior){
        this.flyBehavior=flyBehavior;
        this.quackBehavior=quackBehavior;
    }

    public void performFly(){
        flyBehavior.fly();
    }

    public void performQuack(){
        quackBehavior.quack();
    }

    public void setFlyBehavior(FlyBehavior flyBehavior){
        this.flyBehavior=Objects.requireNonNull(flyBehavior);
    }

    public void setQuackBehavior(QuackBehavior quackBehavior){
        this.quackBehavior=Objects.requireNonNull(quackBehavior);
    }

    public void swim(){
        System.out.println("All ducks can float");
    }

    public abstract void display();
}

//concrete contexts

class MallardDuck extends Duck{

    public MallardDuck(){
        super(new FlyWithWings(),new NormalQuack());
    }

    @Override
    public void display() {
        System.out.println("Mallard Duck");
    }
}

class ModelDuck extends Duck{

    public ModelDuck(){
        super(new FlyNoWay(),new NormalQuack());
    }

    @Override
    public void display() {
        System.out.println("Model Duck");
    }
}

public class StrategyDemo {
    public static void main(String[] args){
        Duck mallard=new MallardDuck();

        mallard.performQuack();
        mallard.performFly();

        Duck model= new ModelDuck();

        model.performFly();

        model.setFlyBehavior(new FlyRocketPowered());
        model.performFly();
    }
}
