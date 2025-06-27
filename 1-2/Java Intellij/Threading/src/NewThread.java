import java.net.Socket;

public class NewThread implements Runnable{
    Thread t;
    NewThread(String name){
        t=new Thread(this,name);
        System.out.println("Child Thread: "+t);
    }

    public void run(){
        try{
            for(int i=5;i>0;i--){
                System.out.println("Child Thread: "+i);
                Thread.sleep(500);
            }
        }
        catch(InterruptedException e){
            e.printStackTrace();
        }
        System.out.println("Exiting Child Thread: "+t);
    }
}
