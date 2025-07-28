package HouseOfTheDeads2;

import util.SocketWrapper;

import java.io.IOException;
import java.util.Scanner;

public class WriteThread implements Runnable{
    SocketWrapper socketWrapper;
    String name;
    Thread t;
    public WriteThread(SocketWrapper socketWrapper,String name) {
        this.socketWrapper=socketWrapper;
        t = new Thread(this);
        this.name=name;
        t.start();

    }

    public void run(){
        Scanner scanner=new Scanner(System.in);
        while(true){
            String s=scanner.nextLine();
            try {
                socketWrapper.write(name+" : "+s);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
