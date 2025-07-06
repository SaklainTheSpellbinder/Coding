class A {
    int i, j;

    void showij() {
        System.out.println(i + " " + j);
    }
}

class B extends A {
    int k;

    void showk() {
        System.out.println(k);
    }

    void sum() {
        System.out.println(i + j + k);
    }
}

class MoreJao{
     static void f1(){
        System.out.println("hello");
    }
}

class MoreGechi extends MoreJao{
    static void f1(){
        System.out.println("more jawa bhalo");
    }
}

public class SimpleInheritance {
    public static void main(String[] args) {
        A superOb = new A();
        superOb.i = 10;
        superOb.j = 20;
        superOb.showij();
        B subOb = new B();
        subOb.i = 7;
        subOb.j = 8;
        subOb.k = 9;
        subOb.showij();
        subOb.showk();
        subOb.sum();

        MoreJao m=new MoreGechi();
        m.f1();

        //MoreJao jodi interface hoto tahole m ke evabe m.f1() lekha jeto na....karon interface er shomoy just interface er nam diyei static call kora jaabe...no instance
    }
}
