public class Bank {
    static class Message{
        static void alert(){
            System.out.println("banking system is ready");
        }
    }

    public static void main(String[] args){
        Bank.Message.alert();
    }
}
