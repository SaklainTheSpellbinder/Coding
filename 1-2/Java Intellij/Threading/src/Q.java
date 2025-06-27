public class Q {
    public int n;
    boolean valueSet=false;
    synchronized public int get(){
        while(!valueSet){
            try{
                wait();
            }
            catch(InterruptedException e){
                System.out.println(e);
            }
        }
        System.out.println("Got: "+n);
        valueSet=false;
        notify();
        return n;
    }

    synchronized public void put(int n) {
        while(valueSet){
            try {
                wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
        this.n = n;
        valueSet=true;
        System.out.println("Put: " + n);
        notify();
    }
}
