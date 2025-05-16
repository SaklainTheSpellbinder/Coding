public class StaticBockExample {
    static int value;

    static{
        System.out.println("Static Block called");
        value=432;
    }
    public StaticBockExample(){
        System.out.println("Constructor called");
    }

    public static void main(String[] args) {
        System.out.println("Main starts");
        value=4;
        StaticBockExample obj=new StaticBockExample();
        System.out.println("Value "+value);
    }
}
