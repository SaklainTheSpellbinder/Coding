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
        System.out.println("Ami bolchi More jao");
    }

    void nonstaticf(){
        System.out.println("Ami More Jabo");
    }
}

class MoreGechi extends MoreJao{
    static void f1(){
        System.out.println("more jawa bhalo");
    }
    //static method er override hoyna...method hiding hoy

    void nonstaticf(){
        System.out.println("Ami More Gechi");
    }
}

interface tintin{
    static void f1(){
        System.out.println("hello");
    }
    //static void f2();// static method should have body
    //private void f2();//private method should have a body
}

class tingtong implements tintin{
    //f1 implement korar kono dorkar nai....korleo eta override hobe na....method hiding hobe and tintin er instance diye ei f1 ke daaka jabe na
    static void f1(){
        System.out.println("tingtong er bhitore");
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
        m.f1(); //ekhane m MoreJao er function ta call kore jekhane jodi function ta static na hoto tahole MoreGechi er ta korto karon oita overrride hoto....but static method override hoyna eta method hiding hoy
        m.nonstaticf();// jemon eta dynamic method dispatch er karone MoreGechi er function ke ee daakbe....so eta runtime e thik hoy....but static ta compile time e class load howar shomoy ee thik hoye jay....tai etay dynamic method dispatch nai

        tintin.f1();
        tintin t;
        //t.f1();
        tintin t1=new tingtong();
        //t1.f1(); //static method can only be called on its containing interface
        //MoreJao jodi interface hoto tahole m ke evabe m.f1() lekha jeto na....karon interface er shomoy just interface er nam diyei static call kora jaabe...no instance
        //t1.f1(); //eta use kore tingtong er ta oo daake jabe na...karon method hiding hoy....tintin tingtong er ta r dekhte parena
        tingtong maramari=new tingtong();
        maramari.f1();
        tingtong.f1();
    }
}
