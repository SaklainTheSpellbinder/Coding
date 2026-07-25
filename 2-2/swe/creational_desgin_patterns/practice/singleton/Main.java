import java.sql.Connection;

class Dbconnection{
    private static Dbconnection instance =null;
    private final Connection connection;

    private Dbconnection(){
        this.connection=connectToDatabase();
    }

    private Connection connectToDatabase(){
        return null;
    }

    public static synchronized Dbconnection getDbConnection(){
        if(instance == null){
            instance=new Dbconnection();
        }
        return instance;
    }
}



public class Main{
    public static void main(String[] args) {
        Dbconnection con1=Dbconnection.getDbConnection();
        Dbconnection con2=Dbconnection.getDbConnection();

        System.out.println(con1==con2);
    }
}