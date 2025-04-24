class Animal {
    void eat(){
        System.out.println("Eats anything");
    }

    Animal(String name) {
        System.out.println("Animal: " + name);
    }
}

class Dog extends Animal {
    @Override
    void eat(){
        super.eat();
        System.out.println("Eats dog food");
    }
    Dog() {
        super("Doggo"); // must be the first line
    }
}


class A{
    A(){
        System.out.println("A's constructor");
    }
}

class B extends A{
    B(){
        super();// eta na dileo A class er constructor call hobe
        // but super() is used to explicitly call the constructor of the superclass (A) before executing the constructor of the subclass (B).
        System.out.println("B's constructor");
    }
}

public class Inheritancetest {
    public static void main(String[] args){
        @SuppressWarnings("unused")
        B b1=new B();
        Dog d=new Dog();
        d.eat();
    }

}
// In this example, when we create an object of class B, the constructor of class A is called first, followed by the constructor of class B.
// This is because class B extends class A, and the constructor of the superclass (A) is always called before the constructor of the subclass (B).
// The output will be:
// A's constructor
// B's constructor
// This demonstrates the concept of constructor chaining in inheritance, where the constructor of the superclass is called before the constructor of the subclass.