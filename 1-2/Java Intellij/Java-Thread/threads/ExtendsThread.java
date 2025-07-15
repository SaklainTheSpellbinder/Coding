package threads;

class NewThread2 extends Thread {

    NewThread2() {
        super("Extends Thread");
        //start();
    }
//start dile run call hoy.....but alada kore....emon na je etar pore ja kora hoise ogula cholbe na eta shesh na howa porjonto
    // This is the entry point for the thread.
    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName());
        System.out.println("Starting child thread.");
        try {
            for (int i = 100; i > 0; i--) {
                System.out.println("Child Thread: " + i);
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println("Child interrupted.");
        }
        System.out.println("Exiting child thread.");
    }
}

public class ExtendsThread {
    public static void main(String[] args) throws Exception {
        NewThread2 newThread2 = new NewThread2();
        //newThread2.start(); eta dilei khali ekshate cholbe....run call dile just emne func er moto kaj korbe....oita thread na
        newThread2.run();//eta thread hobe na....eta aage child run hobe then child run shesh hobe then main er baaki gula cholbe....
        for (int i = 500; i > 0; i--) {
            System.out.println("Main Thread: " + i);
            Thread.sleep(2000);
        }
    }
}
