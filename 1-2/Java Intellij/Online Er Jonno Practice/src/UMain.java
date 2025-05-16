public class UMain {
    public static void main(String[] args) {
        Account[] acc = new Account[3];
        acc[0] = new Account(101, "Tanvir", 5000);
        acc[1] = new Account(102, "Riyad", 8000);
        acc[2] = new Account(103, "Arif", 4000);

        for (Account a : acc) {
            System.out.println(a); // calls toString()
        }

        Account.printTotalAccounts(); // static method
    }
}
