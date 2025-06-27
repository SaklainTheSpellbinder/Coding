public class ExtendThread extends Thread {
    ExtendThread(String name){
        super(name);
        System.out.println("Child Thread"+ this);
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
        System.out.println("Exiting Child Thread: "+this);
    }
}