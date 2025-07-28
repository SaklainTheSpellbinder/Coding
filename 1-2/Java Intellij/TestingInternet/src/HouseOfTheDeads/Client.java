package HouseOfTheDeads;

import util.SocketWrapper;

import java.io.IOException;
import java.util.Scanner;

public class Client {
    public SocketWrapper socketWrapper;

    Client(String serverAddress, int serverPort) throws IOException {
        System.out.println("Enter the name of you: ");
        Scanner scanner = new Scanner(System.in);
        String name=scanner.nextLine();
        socketWrapper=new SocketWrapper(serverAddress,serverPort);
        socketWrapper.write(name);
        new ReadThreadClient(socketWrapper);
        new WriteThread(socketWrapper,name);
    }

    public static void main(String args[]) throws IOException {
        String serverAddress = "0.tcp.in.ngrok.io";
        int serverPort = 16660;
        new Client(serverAddress, serverPort);
    }
}
