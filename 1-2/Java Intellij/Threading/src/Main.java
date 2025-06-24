import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Main {
    public static void main(String[] args) {

        System.out.println("Hello...hehe waiting for clients babe");
        try {
            ServerSocket ss=new ServerSocket(9806);
            Socket client1=ss.accept();
            System.out.println("Connection established with client1");
            Socket client2=ss.accept();
            System.out.println("Connection established with client2");

            new Thread(() -> forwardAudio(client1,client2)).start();
            new Thread(() -> forwardAudio(client2,client1)).start();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void forwardAudio(Socket from,Socket to){
        try(InputStream in=from.getInputStream(); OutputStream out=to.getOutputStream()){
            byte[] buffer =new byte[1024];
            int count;
            while((count=in.read(buffer))>0){
                out.write(buffer,0,count);
            }
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}