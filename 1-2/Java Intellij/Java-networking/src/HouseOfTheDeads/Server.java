package HouseOfTheDeads;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;
import util.SocketWrapper;

public class Server {
    ServerSocket serversocket;
    HashMap clientMap;
    Server(){
        clientMap=new HashMap();
        try{
            serversocket=new ServerSocket(55555);
            while(true){
                Socket socket=serversocket.accept();
                serve(socket);
            }
        }
        catch(Exception e){
            e.printStackTrace();
        }
        finally{
            serversocket = null;
        }
    }

    public static void main(String[] args){
        Server server=new Server();
    }

    public void serve(Socket socket) throws IOException, ClassNotFoundException {
        SocketWrapper socketWrapper=new SocketWrapper(socket);
        String clientName=(String) socketWrapper.read();
        clientMap.put(clientName,socketWrapper);
        System.out.println("Client "+clientName+" connected");
        new ReadThreadServer(clientMap,socketWrapper);
    }
}