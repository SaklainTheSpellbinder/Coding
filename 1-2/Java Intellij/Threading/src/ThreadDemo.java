public class ThreadDemo {
    public static void main(String[] args) {
        NewThread newThread = new NewThread("one");
        newThread.t.start();
        ExtendThread extendThread = new ExtendThread("two");
        extendThread.start();
        ExtendThread extendThread2 = new ExtendThread("three");
        extendThread2.start();
        System.out.println("Thread one is alive: "+ newThread.t.isAlive());
        System.out.println("Thread two is alive: "+ extendThread.isAlive());
        System.out.println("Thread three is alive: "+ extendThread2.isAlive());

        try{
            newThread.t.join();
            extendThread2.join();
            extendThread.join();
        }
        catch(Exception e){
            System.out.println(e);
        }
        try{
            for(int i=5;i>0;i--){
                System.out.println("Main Thread: "+i);
                Thread.sleep(1000);
            }
        }
        catch(Exception e){
            e.printStackTrace();
        }
        System.out.println("Exiting Main Thread");
    }
}
