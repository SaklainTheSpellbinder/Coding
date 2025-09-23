abstract class S {
    // abstract method
    abstract void call();

    // concrete methods are still allowed in abstract classes
    void call2() {
        System.out.println("This is a concrete method");
    }
}

class T extends S {
    void call() {
        System.out.println("T's implementation of call");
    }
}

class AbstractDemo {
    public static void main(String args[]) {
        // S s = new S(); // S is abstract; cannot be instantiated
        S s = new S() {
            @Override
            void call() {
                System.out.println("In Call Method");
            }

            void f1(){ //extra jinish pati o likhte parbo amra //but lol eta to subclass er jinish jeta ekta anonymous subclass....so amra to parent er instance diye daakbo....
                // but parent to subclass er alada method dekhtei pabe na.....so amra ei method likheo labh nai karon access korte to parbo na kono bhabe....
                // like typecast lagbe but kishe typecast korbo jekhane subclass ee anonymous
                System.out.println("hello");
            }
        };
        s.call();
        T t = new T();
        t.call();
        t.call2();
        //s.f1(); s to f1 ke chinei na eta or child er method
    }
}
