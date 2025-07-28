package HouseOfTheDeads2;

import util.SocketWrapper;

import java.io.IOException;
import java.util.ArrayList;

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
                Object o= socketWrapper.read();
                if(o instanceof ArrayList<?> list){
                    System.out.println(list);
                }
                else if(o instanceof String){
                    s=(String)o;
                    System.out.println(s);
                }
            } catch (IOException e) {
                throw new RuntimeException(e);
            } catch (ClassNotFoundException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
