class Logger{
    private static Logger instance;

    private Logger(){
        System.out.println("Logging in....");
    }

    public static synchronized Logger getInstance(){
        if(instance==null){
            instance=new Logger();
        }
        return instance;
    }
}

public class Main2 {
    public static void main(String[] args) {
        Logger in1=Logger.getInstance();
        Logger in2=Logger.getInstance();

        System.out.println(in1==in2);
    }
    
}
