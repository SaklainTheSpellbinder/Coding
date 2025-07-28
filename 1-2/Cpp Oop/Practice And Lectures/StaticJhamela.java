class Shared { 
    int staticCount = 0; 
    int instanceCount = 0; 
    public void incrementStatic(String threadName) { 
        staticCount++; 
        System.out.println(threadName + "staticCount: " + staticCount); 
    } 
    public synchronized void incrementInstance(String threadName) { 
        instanceCount++; 
        System.out.println(threadName + "instanceCount: " + instanceCount); 
    } 

    void printCount()
    {
        System.out.println(staticCount);
    }
 
}

public class StaticJhamela{
    public static void main(String[] args) throws InterruptedException { 
        Shared shared1 = new Shared(); 
        Shared shared2 = new Shared();
        Thread t1 = new Thread(() -> { 
            for (int i = 0; i < 100; i++){

           
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
                shared1.incrementStatic("Thread1"); 
            // for (int i = 0; i < 2; i++) 
            //     shared1.incrementInstance("Thread1"); 
             }
        }, "Thread1"); 
        Thread t2 = new Thread(() -> { 
            for (int i = 0; i < 100; i++){
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
                shared1.incrementStatic("Thread2"); 
            // for (int i = 0; i < 2; i++) 
            //     shared2.incrementInstance("Thread2"); 
            }
        }, "Thread2"); 
        t1.start(); 
        t2.start(); 
        t1.join();
        t2.join();
        shared1.printCount();
        //System.out.println(staticCount);
    } 
}