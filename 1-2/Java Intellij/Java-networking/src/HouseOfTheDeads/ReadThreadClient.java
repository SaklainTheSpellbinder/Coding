package HouseOfTheDeads;

import util.SocketWrapper;

import java.io.IOException;

public class ReadThreadClient implements Runnable {
    SocketWrapper socketWrapper;
    Thread t;
    public ReadThreadClient(SocketWrapper socketWrapper) {
        this.socketWrapper=socketWrapper;
        t=new Thread(this);
        t.start();
    }

    public void run() {
        while(true){
            String s;
            try {
                s=(String) socketWrapper.read();
            } catch (IOException e) {
                throw new RuntimeException(e);
            } catch (ClassNotFoundException e) {
                throw new RuntimeException(e);
            }
            System.out.println(s);
        }
    }
}
