package synchronization;

class TestClass {
    public void f0() {
        for (int i = 0; i < 5; i++) {
            System.out.println(Thread.currentThread().getName() + " " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public synchronized void f1() {
        for (int i = 0; i < 5; i++) {
            System.out.println(Thread.currentThread().getName() + " " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public synchronized void f2() {
        for (int i = 0; i < 5; i++) {
            System.out.println(Thread.currentThread().getName() + " " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public synchronized static void fs() {
        for (int i = 0; i < 5; i++) {
            System.out.println(Thread.currentThread().getName() + " " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

}

public class SynchronizedTest {
    public static void main(String[] args) {
        TestClass t1 = new TestClass();
        TestClass t2 = new TestClass();
        new Thread(t1::f1, "T1").start();   //T1 r T2 ekshjatte chalale pera nai.....karon 2 ta alada object theke call kortese run func...so doesn't matter
        //new Thread(t2::f1, "T2").start();
         new Thread(t1::f2, "T4").start();
         new Thread(t1::f0, "T5").start();//eta onnoder shate chole parbe karon eta to synchronized na...so eta boshe thakbe na
         new Thread(TestClass::fs, "T6").start();//static er shate nonstatic er boshe thakar kono relation nai
         //new Thread(TestClass::fs, "T7").start();
    }
}
