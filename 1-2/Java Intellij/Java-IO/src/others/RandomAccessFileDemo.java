package others;

import java.io.RandomAccessFile;

public class RandomAccessFileDemo {
    public static void main(String[] args) throws Exception {
        RandomAccessFile file = new RandomAccessFile("src/random.txt",  "rw");//rw mode truncate kore na...aager upor overwrite kore
        file.write("Hello".getBytes());
        System.out.println(file.getFilePointer());
        file.seek(0);
        System.out.println(file.getFilePointer());//offset the return kore...moja c vibe ashche
        System.out.println(file.readLine());
        file.seek(10);//majhkaner gulo shob mara kheyeche.....0 or undefined kichu diye padding kore
        file.write("World".getBytes());
        file.seek(0);
        System.out.println(file.readLine());
        file.close();
    }
}
