public class tingtong{
    public static void main(String[] args) {
        if (args.length > 0) {
            System.out.println("Welcome, " + args[0]);
        } else {
            System.out.println("Please pass your name as command line argument.");
        }
    }
}
