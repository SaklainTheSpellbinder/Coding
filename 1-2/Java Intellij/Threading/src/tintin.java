
class tintinmohashoy extends Thread{

    public tintinmohashoy(String str) {
        super(str);
    }

    public void run(){
        try {
            for(int i=5;i>=0;i--){
                System.out.println("Child Thread: "+i);
            }
        } catch (Exception e) {
        }
    }
    
}

public class tintin {
    public static void main(String[] args) {
        tintinmohashoy t=new tintinmohashoy("pimimi");
        t.start();
        Thread t1=Thread.currentThread();
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        for(int i=5;i>=0;i--){
                System.out.println("Child Thread: "+i);
        }
    }
}
