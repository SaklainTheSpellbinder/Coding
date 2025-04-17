class Animal {
    void sound() {
        System.out.println("Animal makes a sound");
    }
}

class Dog extends Animal {
    @Override
    void sound() {
        System.out.println("Dog barks");
    }
}

class Cat extends Animal {
    @Override
    void sound() {
        System.out.println("Cat meows");
    }
}


public class RuntimePolymorphism{
    public static void main(String[] args){
        Animal a = new Dog(); // Upcasting
        a.sound(); // Calls the overridden method in Dog class

        Animal b = new Cat(); // Upcasting
        b.sound(); // Calls the overridden method in Cat class

        Animal c = new Animal(); // Upcasting
        c.sound(); // Calls the method in Animal class
    }
}