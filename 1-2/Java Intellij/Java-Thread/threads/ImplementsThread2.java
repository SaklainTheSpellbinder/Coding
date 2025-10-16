package threads;

class NewThread3 implements Runnable {
    @Override
    public void run() {
        try {
            for (int i = 100; i > 0; i--) {
                System.out.println("Child Thread: " + i+ " " + Thread.currentThread().getName());
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println("Child interrupted.");
        }
        System.out.println("Exiting child thread.");
    }
}

public class ImplementsThread2 {
    public static void main(String[] args) {
        Runnable r = new NewThread3();
        Thread t = new Thread(r,"Tingtong first thread");
        t.start();

        NewThread3 nt=new NewThread3();
        Thread t1=new Thread(nt,"Tintin second thread");
        t1.start();

        new Thread(r,"hello").start(); //eta emne first thread second thread er shatei chobe but jodi amra run er aage synchonized likhi tajjole first r third ekshate cholte parbe na
    }
}