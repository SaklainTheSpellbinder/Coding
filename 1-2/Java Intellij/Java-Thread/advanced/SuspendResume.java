package advanced;

// Suspending and resuming a thread the modern way.
class NewThreadSR implements Runnable {
    String name; // name of thread
    Thread t;
    boolean suspendFlag;

    NewThreadSR(String threadname) {
        name = threadname;
        t = new Thread(this, name);
        System.out.println("New thread: " + t);
        suspendFlag = false;
        t.start(); // Start the thread
    }

    // This is the entry point for thread.
    public void run() {
        try {
            for (int i = 15; i > 0; i--) {
                System.out.println(name + ": " + i);
                Thread.sleep(200);
                synchronized (this) {//nijer object ei lock mere boshe ache lol.....onno keo etar monitor e eshe(actually mainthread by calling myresume ) notify na dile eta wait ei thakbe....mane etar run ee cholbe na totokkhon
                    while (suspendFlag) {
                        wait();
                    }
                }
            }
        } catch (InterruptedException e) {
            System.out.println(name + " interrupted.");
        }
        System.out.println(name + " exiting.");
    }

    synchronized void mySuspend() {
        suspendFlag = true;
    }//eta mainly main class er je implicit thread ache oita ekhane dhuke and tai synchronized lagbe
    //monitor on this object.....ekhon main eshe etay notify diye chole jay,,,,er madhhomei mainly ei thread ti wait theke ber hote pare

    synchronized void myResume() {
        suspendFlag = false;
        notify();
    }
}
//wait bhai er kaj->
//tells the calling thread to give up the monitor and go to
//sleep until some other thread enters the same monitor
//and calls notify( ) or notifyAll()
//mainly same monitor e (same object er any synchronized method or oi object er block) abar keo dhuke notify dilei hoye jabe

public class SuspendResume {
    public static void main(String[] args) {
        NewThreadSR ob1 = new NewThreadSR("One");
        NewThreadSR ob2 = new NewThreadSR("Two");
        try {
            Thread.sleep(1000);
            ob1.mySuspend();
            System.out.println("Suspending thread One");
            Thread.sleep(1000);
            ob1.myResume();
            System.out.println("Resuming thread One");
            ob2.mySuspend();
            System.out.println("Suspending thread Two");
            Thread.sleep(1000);
            ob2.myResume();
            System.out.println("Resuming thread Two");
        } catch (InterruptedException e) {
            System.out.println("advanced.Main thread Interrupted");
        }
        // wait for threads to finish
        try {
            System.out.println("Waiting for threads to finish.");
            ob1.t.join();
            ob2.t.join();
        } catch (InterruptedException e) {
            System.out.println("advanced.Main thread Interrupted");
        }
        System.out.println("advanced.Main thread exiting.");
    }
}
