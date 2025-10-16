interface MyInterface {
    default void greet() {
        System.out.println("Hello from the interface!");
    }
}

interface hehe{
    default void greet(){
        System.out.println("Hello from hehe");
    }
}

abstract class MyAbstractClass2 implements MyInterface {
    abstract public void greet();
}

class MyConcreteClass extends MyAbstractClass2 implements hehe,MyInterface {
    //override kora ee lagbe  //oi default r use kora jabe na

    @Override
    public void greet() {
        hehe.super.greet();
        //MyInterface.super.greet();
        System.out.println("Jo main raat hu...  ");
    }
}

public class  MyAbstractClass{
    public static void main(String[] args) {
        MyConcreteClass obj = new MyConcreteClass();
        obj.greet();
    }
}