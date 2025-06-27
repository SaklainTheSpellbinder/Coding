import javax.sound.sampled.*;
import java.net.*;

public class P2PAudioPeer {
    public static void main(String[] args) throws Exception {
//        if (args.length != 3) {
//            System.err.println("Usage: java P2PAudioPeer <localPort> <remoteHost> <remotePort>");
//            System.exit(1);
//        }
//        int localPort    = Integer.parseInt(args[0]);
//        String remoteIp  = args[1];
//        int remotePort   = Integer.parseInt(args[2]);
        int localPort=50000;
        String remoteIp="192.168.0.107";
        int remotePort=50000;

        DatagramSocket socket = new DatagramSocket(localPort);
        InetSocketAddress peerAddr = new InetSocketAddress(InetAddress.getByName(remoteIp), remotePort);

        AudioFormat fmt = new AudioFormat(8000f, 16, 1, true, false);

        TargetDataLine mic = AudioSystem.getTargetDataLine(fmt);
        mic.open(fmt, 512);
        mic.start();

        SourceDataLine speakers = AudioSystem.getSourceDataLine(fmt);
        speakers.open(fmt, 512);
        speakers.start();

        Thread sendThread = new Thread(() -> {
            try {
                byte[] buf = new byte[256];
                DatagramPacket pkt = new DatagramPacket(buf, buf.length, peerAddr);
                while (!Thread.interrupted()) {
                    int len = mic.read(buf, 0, buf.length);
                    if (len > 0) {
                        pkt.setLength(len);
                        socket.send(pkt);
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }, "Audio-Sender");
        sendThread.setDaemon(true);
        sendThread.start();

        Thread recvThread = new Thread(() -> {
            try {
                byte[] buf = new byte[512];
                DatagramPacket pkt = new DatagramPacket(buf, buf.length);
                while (!Thread.interrupted()) {
                    socket.receive(pkt);
                    speakers.write(pkt.getData(), 0, pkt.getLength());
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }, "Audio-Receiver");
        recvThread.setDaemon(true);
        recvThread.start();

        System.out.printf("P2P audio running on UDP %d → %s:%d\n", localPort, remoteIp, remotePort);
        System.out.println("Press ENTER to stop...");
        System.in.read();

        sendThread.interrupt();
        recvThread.interrupt();
        mic.stop();      mic.close();
        speakers.stop(); speakers.close();
        socket.close();
    }
}
