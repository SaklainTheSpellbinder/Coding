import java.io.*;
import java.net.*;
import javax.sound.sampled.*;

public class client {

    public static void main(String[] args) {
        System.out.println("Client started");
        try {
            Socket soc= new Socket("192.168.0.108", 9806);
            AudioFormat format = new AudioFormat(8000.0f, 16, 1, true, false);
            TargetDataLine mic=AudioSystem.getTargetDataLine(format);
            mic.open(format);
            mic.start();

            SourceDataLine speakers=AudioSystem.getSourceDataLine(format);
            speakers.open(format);
            speakers.start();

            new Thread(() -> {
                try(OutputStream out=soc.getOutputStream()){
                    byte[] buffer=new byte[1024];
                    while(true){
                        int count=mic.read(buffer,0,buffer.length);
                        out.write(buffer,0,count);
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }).start();

            new Thread(() -> {
                try(InputStream in=soc.getInputStream()){
                    byte[] buffer=new byte[1024];
                    int count;
                    while((count=in.read(buffer))>0){
                        speakers.write(buffer,0,count);
                    }
                }
                catch(Exception e){
                    e.printStackTrace();
                }
            }).start();

        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (LineUnavailableException e) {
            throw new RuntimeException(e);
        }
    }
}
