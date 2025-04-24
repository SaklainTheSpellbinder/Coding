interface Animal{
    void sound();
}

class Dog implements Animal{
    @Override
    public void sound(){
        System.out.println("Dog barks");
    }
}

interface A {
    void show();
}

interface B {
    void display();
}

class MyClass implements A, B {
    @Override
    public void show() {
        System.out.println("Showing A");
    }

    @Override
    public void display() {
        System.out.println("Displaying B");
    }
}

interface Settings {
    int MAX = 100;   // implicitly public static final
    int MIN = 0;
}
//cannot change interface variables-- they're like constants

class SystemCheck {
    void printLimits() {
        System.out.println(Settings.MAX + ", " + Settings.MIN);
    }
}



interface Vehicle {
    default void start() {
        System.out.println("Starting vehicle...");
    }

    static void honk() {
        System.out.println("Honking...");
    }
}

class Car implements Vehicle {}



@FunctionalInterface
interface Greeting {
    void sayHello();//can consist only one abstract method so that we can use lambda expression
}



interface Payment {
    void pay(int amount);
}

class CreditCard implements Payment {
    @Override
    public void pay(int amount) {
        System.out.println("Paid " + amount + " via Credit Card");
    }
}

class PayPal implements Payment {
    @Override
    public void pay(int amount) {
        System.out.println("Paid " + amount + " via PayPal");
    }
}



public class intergacetest {
    public static void main(String[] args){
        Dog d= new Dog();
        d.sound();
        MyClass m= new MyClass();
        m.show();
        m.display();
        SystemCheck s = new SystemCheck();
        s.printLimits();


        Car c = new Car();
        c.start();           // default method
        Vehicle.honk();      // static method


        //usage of lambda
        Greeting g= ()-> System.out.println("Hello, Friend!");//eta object create kora na.args..args.amra lambda func use korechi
        g.sayHello();


        Payment p;

        p = new CreditCard();
        p.pay(500);

        p = new PayPal();
        p.pay(700);
    }
}
//interfaces can't have constructors
// can implement multiple interfaces
//can extend other interfaces
//can't create objects with interfaces
//interface methods can't be private
