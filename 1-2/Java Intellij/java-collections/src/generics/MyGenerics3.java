package generics;

class X {
    int x;

    void f1() {
        System.out.println("In f1");
    }
}

interface Y {
    void f2();
}

interface Z {
    void f3();
}

class MyX extends X implements Y, Z {
    public void f2() {
        System.out.println("In f2");
    }

    public void f3() {
        System.out.println("In f3");
    }
}

public class MyGenerics3<T extends X & Y & Z> {/// ekhane T extends X & Y & Z dara mainly bujhay hocche T X class ke extend korbe and Y, Z interface ke implement korbe....eta must maante hobe.....generic bounding
    private T a;

    public void setObj(T a) {
        this.a = a;
    }

    public T getObj() {
        return this.a;
    }

    public static void main(String[] args) {
        MyGenerics3<MyX> myGenerics = new MyGenerics3<>();
        MyX objX = new MyX();
        myGenerics.setObj(objX);
        myGenerics.a.f1();
        myGenerics.a.f2();
        myGenerics.a.f3();
        myGenerics.getObj().f3();
        System.out.println(myGenerics.getObj());
    }
}