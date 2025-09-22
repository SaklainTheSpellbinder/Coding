class Outer1 {
    private int outer_x = 100;

    Outer1() {
        System.out.println("Outer1 Constructor");
    }

    void test() {
        Inner inner = new Inner();
        System.out.println(inner.inner_x); //object diye private jinish access korte parbe Inner class er
        //System.out.println(x); //inner er object chara oitar x access korte parbe na...even if public
        inner.display();

    }

    // this is an inner class
    class Inner { //etake private class likhle main theke r inner er object banano jabe na
        private int inner_x = 200;
        public int x;

        Inner() {
            System.out.println("Inner Constructor");
        }

        void display() {
            System.out.println(outer_x);
        } //outer er private kichu access korteo kichu lagbe na object o na kichui na
    }
}

public class InnerClassDemo1 {
    public static void main(String[] args) {
        Outer1 outer = new Outer1();
        outer.test();
        Outer1.Inner innerObj = outer.new Inner();
        innerObj.display();
        
    }
}
