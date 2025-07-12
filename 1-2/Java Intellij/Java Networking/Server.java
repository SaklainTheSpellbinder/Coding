import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
//local host mane hocche.... 127.0.0.1
public class Server{
    ServerSocket ss;
    int clientcount=0;
    Server(){
        try {
            ss=new ServerSocket(22222);
            System.out.println("Server is waiting");

            Socket cc=ss.accept();
            System.out.println("Server accepts a client..");
            serve(cc);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        Server server=new Server();


    }

    public void serve (Socket client){
        clientcount++;
        try {
            ObjectOutputStream oos=new ObjectOutputStream(client.getOutputStream());
            ObjectInputStream ois=new ObjectInputStream(client.getInputStream());
            System.out.println(ois.readObject() + "," + clientcount);
            oos.writeObject("Hello Client: "+ clientcount);
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        catch (ClassNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
    //data serializing and deserializing......... implements Serializable.....kono method implement kora laage na....but user defined object dile....eta lagbe...karon network to low level e data pathay
}