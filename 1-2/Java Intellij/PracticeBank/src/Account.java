public class Account {
    private int accountNumber;
    private String customerName;
    private double balance;

    public Account(int accountNumber, String customerName, double balance) {
        this.accountNumber=accountNumber;
        this.customerName=customerName;
        this.balance=balance;
    }

    public int getAccountNumber(){
        return accountNumber;
    }

    public String getCustomerName(){
        return customerName;
    }

    public double getBalance(){
        return balance;
    }

    public void deposit(double amount){
        balance+=amount;
    }

    public void withdraw(double amount){
        balance-=amount;
    }


}
