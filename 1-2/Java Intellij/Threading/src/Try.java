public class Try {
    interface i1 {
        static void f3(){}
    }

    class c2 implements i1 {
        // static void f3() {
        //     System.out.println("c2's f3");
        // }
    }

    public static void main(String[] args) {
        i1.f3();
        c2.f3();
    }
}
