public class Branch {
    private int branchId;
    private String branchName;
    private Account[] accounts;
    private int accountCount;

    static Branch[] branches=new Branch[20];
    static int totalBranches=0;

    public Branch(int branchId, String branchName){
        this.branchId=branchId;
        this.branchName=branchName;
        accounts=new Account[10];
        accountCount=0;
        branches[totalBranches++]=this;
    }

    public void addAccount(Account acc){
        accounts[accountCount++]=acc;
    }

    public double getTotalBalance(){
        double ans=0.0;
        for(int i=0;i<accountCount;i++){
            ans+=accounts[i].getBalance();
        }
        return ans;
    }

    public Account getTopAccount(){
        int best=0;
        for(int i=0;i<accountCount;i++){
            if(accounts[i].getBalance()>accounts[best].getBalance()){
                best=i;
            }
        }
        return accounts[best];
    }

    static void transfer(Account from,Account to,double amount){
        from.withdraw(amount);
        to.deposit(amount);
    }

    static void printAllBranchesInfo(){
        for(int i=0;i<totalBranches;i++){
            System.out.println("Branch Id: "+branches[i].branchId+", Branch Name: "+branches[i].branchName);
            for(int j=0;j<branches[i].accountCount;j++){
                System.out.println("Account Number: "+branches[i].accounts[j].getAccountNumber()+", Customer Name: "+branches[i].accounts[j].getCustomerName()+", Balance: "+branches[i].accounts[j].getBalance());
            }
        }
    }

    static void printRichestCustomer(){
        int besti=0;
        int bestj=0;
        for(int i=0;i<totalBranches;i++){
            for(int j=0;j<branches[i].accountCount;j++){
                if(branches[i].accounts[j].getBalance()>branches[besti].accounts[bestj].getBalance()){
                    besti=i;
                    bestj=j;
                }
            }
        }
        System.out.println("Richest Customer: "+branches[besti].accounts[bestj].getCustomerName());
        System.out.println("Account Number: "+branches[besti].accounts[bestj].getAccountNumber());
        System.out.println("Balance: "+branches[besti].accounts[bestj].getBalance());
        System.out.println("Branch Name: "+branches[besti].branchName);
    }
}
