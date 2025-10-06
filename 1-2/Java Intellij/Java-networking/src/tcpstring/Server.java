package tcpstring;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

import util.SocketWrapper;



public class Server {
    private ServerSocket serverSocket;
    int count=0;

    Server() {
        try {
            serverSocket=new ServerSocket(44444);
            while (true) {
                Socket clientSocket = serverSocket.accept();
                count++;
                serve(clientSocket,count);
            }
        } catch (Exception e) {
            System.out.println("Server starts:" + e);
        }
    }

    public void serve(Socket clientSocket,int count) throws IOException {
        SocketWrapper socketWrapper = new SocketWrapper(clientSocket);
        socketWrapper.write(count);
        new ReadThread(socketWrapper);
        new WriteThread(socketWrapper, "Server");
    }

    public static void main(String args[]) {
        new Server();
    }
}
