package bytestream;
import java.io.*;

class FileCopyDemo {
    public static void main(String args[]) throws Exception {
        String source = "src/files/src.mp4";
        String destination = "src/files/copy.mp4";
        InputStream in = new FileInputStream(source);
        OutputStream out = new FileOutputStream(destination);

        /*while (true) {
            int c = in.read();
            if (c == -1) break;
            out.write(c);
        }*/
        //in.read();
//        byte[] c=new byte[1024];
//        in.read(c,2,3);
//        out.write(c,2,3);
        PrintWriter pw=new PrintWriter(System.out,true);
        pw.println("orreh ami ekhon pw diye likhchi");
        System.out.println("oi");
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        byte[] b = new byte[1024];
        int chunks = in.available() / b.length;
        for (int i = 0; i < chunks; i++) {
            in.read(b);
            out.write(b);
        }
        b = new byte[in.available()];
        in.read(b);
        out.write(b);


        in=new FileInputStream("src/files/src.mp4");
        out=new FileOutputStream("src/files/copySaklain.mp4");
// a better copy kora.....saklain bhalo ee copy korte pare...noob baccha
        b=new byte[1024];
        int bytesread;
        while((bytesread=in.read(b))!=-1){
            out.write(b,0,bytesread);
        }

        in.close();
        out.close();
    }
}
