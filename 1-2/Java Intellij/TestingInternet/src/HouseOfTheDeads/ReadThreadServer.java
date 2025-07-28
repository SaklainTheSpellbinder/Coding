package HouseOfTheDeads;

import util.SocketWrapper;

import java.io.IOException;
import java.util.HashMap;

public class ReadThreadServer implements Runnable {
    SocketWrapper socketWrapper;
    HashMap clientMap;
    Thread t;

    public ReadThreadServer(HashMap clientMap,SocketWrapper socketWrapper) {
        this.clientMap=clientMap;
        this.socketWrapper=socketWrapper;
        t= new Thread(this);
        t.start();
    }

    @Override
    public void run(){
        while(true){
            String s;
            try {
                s= (String) socketWrapper.read();
            } catch (IOException e) {
                throw new RuntimeException(e);
            } catch (ClassNotFoundException e) {
                throw new RuntimeException(e);
            }
            System.out.println(s);
            for(Object val: clientMap.values() ){
                SocketWrapper sw= (SocketWrapper) val;
                if(!sw.equals(socketWrapper)){
                    try {
                        sw.write(s);
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                }
            }
        }
    }
}
