public class Account {
    private int number;
    private String customer;
    private double balance;

    static int totalAccounts = 0;  // Tracks how many accounts created

    static {
        System.out.println("Account class loaded!");
    }

    public Account(int number, String customer, double balance) {
        this.number = number;
        this.customer = customer;
        this.balance = balance;
        totalAccounts++;
    }

    static void printTotalAccounts() {
        System.out.println("Total accounts created: " + totalAccounts);
    }

    public String toString() {
        return String.format("Acc#%d | %s | $%.2f", number, customer, balance);
    }
}
