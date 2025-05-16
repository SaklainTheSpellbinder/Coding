import java.util.Scanner;

public class ScannerExample {
    public static void greet(String name){
        System.out.println("Hello, "+name+"!");
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter your name");
        String user=sc.nextLine();
        System.out.println("Enter your password");
        String pass=sc.nextLine();
        sc.close();
        greet(user);
    }
}
