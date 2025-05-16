import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // 1. Handle command-line argument (optional name greeting)
        if (args.length > 0) {
            System.out.println("Welcome, " + args[0]);
        } else {
            System.out.println("Run with your name as a command-line argument.");
        }

        // 2. Setup Scanner for user input
        Scanner sc = new Scanner(System.in);

        // 3. Create Branches using array
        Branch[] branches = new Branch[2];
        branches[0] = new Branch(1, "Uttara");
        branches[1] = new Branch(2, "Dhanmondi");

        // 4. Add Accounts to branches
        System.out.println("\nEnter account details for Branch 1:");
        for (int i = 0; i < 2; i++) {
            System.out.print("Account Number: ");
            int accNo = sc.nextInt();
            sc.nextLine(); // clear buffer
            System.out.print("Customer Name: ");
            String name = sc.nextLine();
            System.out.print("Initial Balance: ");
            double bal = sc.nextDouble();
            branches[0].addAccount(new Account(accNo, name, bal));
        }

        System.out.println("\nEnter account details for Branch 2:");
        for (int i = 0; i < 2; i++) {
            System.out.print("Account Number: ");
            int accNo = sc.nextInt();
            sc.nextLine(); // clear buffer
            System.out.print("Customer Name: ");
            String name = sc.nextLine();
            System.out.print("Initial Balance: ");
            double bal = sc.nextDouble();
            branches[1].addAccount(new Account(accNo, name, bal));
        }

        // 5. Static method to print richest customer
        Branch.printRichestCustomer();

        // 6. Static method to print all branch info
        Branch.printAllBranchesInfo();
    }
}
