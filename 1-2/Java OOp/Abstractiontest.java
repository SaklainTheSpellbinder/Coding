abstract class Shape {
    abstract void draw();   // abstract method

    void info() {
        System.out.println("All shapes have areas");
    }
}

class Circle extends Shape {
    @Override
    void draw() {
        System.out.println("Drawing a circle");
    }
}


/*
Abstract classes ->
 * Can have abstract methods	✅ Yes
Can have normal methods	✅ Yes
Can have constructors	✅ Yes
Can have variables	✅ Yes
Can be partially abstracted	✅ Yes
Can extend only one class	✅ (like normal inheritance
*/

//abstract classes with no abstract methods possible

@SuppressWarnings("unused")
abstract class Base {
    void show() {
        System.out.println("Base show");
    }
}

interface tingtong {
    void sound(); // abstract by default
}

@SuppressWarnings("unused")
class bappa implements tingtong{
    @Override
    public void sound(){
        System.out.println("Hehe mara khao");
    }
}



public class Abstractiontest {
    //Partial abstraction	abstract classes
    //Full abstraction	interface
    
    public static void main(String[] args){
        Shape s = new Circle(); // polymorphic use
        s.draw();               // runtime binding
        s.info();               // concrete method
    }
}






