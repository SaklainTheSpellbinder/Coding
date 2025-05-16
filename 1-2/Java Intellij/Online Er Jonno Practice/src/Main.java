public class Main {
    static int staticCounter=0;
    int nonStaticCounter=0;

    public Main(){
        staticCounter++;
        nonStaticCounter++;
    }
    public static void main(String[] args) {
        Main d1=new Main();
        Main d2=new Main();

        System.out.println("Static counter: "+staticCounter);
        System.out.println("Non-static counter: "+d2.nonStaticCounter);
    }
}