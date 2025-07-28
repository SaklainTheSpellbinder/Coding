package HouseOfTheDeads2;

import util.SocketWrapper;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.concurrent.ConcurrentHashMap;

public class ReadThreadServer implements Runnable {
    SocketWrapper socketWrapper;
    ConcurrentHashMap clientMap;
    Thread t;
    String clientName;

    public ReadThreadServer(ConcurrentHashMap clientMap,SocketWrapper socketWrapper,String clientName) {
        this.clientMap=clientMap;
        this.socketWrapper=socketWrapper;
        t= new Thread(this);
        t.start();
        this.clientName=clientName;
    }

    @Override
    public void run(){
        try{
//            new Thread(()->{
//                while(true){
//                    try {
//                        Thread.sleep(500);
//                    } catch (InterruptedException e) {
//                        throw new RuntimeException(e);
//                    }
//                    try {
//                        socketWrapper.write(broadcastonlinelist());
//                    } catch (IOException e) {
//                        throw new RuntimeException(e);
//                    }
//                }
//            }).start();
            while(true) {
                String s;
                try {
                    s = (String) socketWrapper.read();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                } catch (ClassNotFoundException e) {
                    throw new RuntimeException(e);
                }
                System.out.println(s);
                for (Object val : clientMap.values()) {
                    SocketWrapper sw = (SocketWrapper) val;
                    if (!sw.equals(socketWrapper)) {
                        try {
                            sw.write(s);
                        } catch (IOException e) {
                            throw new RuntimeException(e);
                        }
                    }
                }

                //clientMap.forEach((key,value)-> System.out.println(key+" "+value));
            }
        }
        finally {
            if(clientName!=null){
                clientMap.remove(clientName);
                System.out.println(clientName+" hase left");
            }
            try {
                socketWrapper.closeConnection();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }


    ArrayList<String> broadcastonlinelist(){
        return new ArrayList<>(clientMap.keySet());
    }
}
