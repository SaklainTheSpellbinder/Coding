public class MainThread {
    public static void main(String[] args) {
        Thread t=Thread.currentThread();
        System.out.println("Current Thread: "+t);
        t.setName("Saklain");
        System.out.println("Current Thread: "+t);
        for(int i=5;i>0;i--){
            System.out.println(i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

    }
}
