interface A {
    void methodA();
}

interface B extends A {
    void methodB();
}

class C implements B {
    @Override
    public void methodA() {
        System.out.println("methodA");
    }


    @Override
    public void methodB() {
        System.out.println("methodB");
    }
}


/*
 * ✅ Interfaces can extend multiple interfaces too:
interface X {}
interface Y {}
interface Z extends X, Y {}
*/


public class Interfaceinheritance {
    public static void main(String[] args){
        C hehe= new C();
        hehe.methodA();
        hehe.methodB();
    }
}
