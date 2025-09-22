public class StaticTest {
    static int a = 3, b;
    int c;

    public StaticTest() {
        System.out.println("Constructor");
        c = 100;
    }

    {
        System.out.println("Hello World");
        c = 10;
    }

    static void f1(int x) {
        System.out.println("inside f1 now");
        System.out.println("x = " + x);
        System.out.println("a = " + a);  
        System.out.println("b = " + b);
        //System.out.println("c = " + c); // Error  karon static method e non static jinish use kora jayna....and eishob method e this super us e kora jayna
    }

    int f2() {
        return a * b;
    }

    static {
        System.out.println("in the static block");
        b = a * 4;
        //c = b; // Error
    }

    public static void main(String[] args) {
        //kichu howar aagei eije static block ta kaj kore felbe...eta abar obnno kono object create korleo ei class er tao pawa jabe na...eta ekbar ee kaj korbe and jeta class load howar shomoy ee....mane shobar aage
        f1(42); // StaticTest.f1(84);//class er nam diye daako r na diye daako same ee to....eta to same class er bhitorei
        System.out.println("b = " + b);
        //System.out.println("Area = " + f2());   // Error
        StaticTest st = new StaticTest();//ei class er object bananor aage porjonto to non static block cholbe na....but tokhon object create korbo....first e non static block hobe then hocche constructor
        System.out.println(st.c);
        System.out.println(st.f2());
        st.f2();//eta return kore just kintu assign kora hoynai kothao....emnei pore ase rki....noob code
        st.f1(18);//ebhabe ei class er object diyeo daaka jabe static class...
        StaticTest st1 = new StaticTest();//protibar non-static block and constructor call hobe
        StaticTest st2 = new StaticTest();
    }
}
