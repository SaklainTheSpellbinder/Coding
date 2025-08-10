package characterstream;
import java.io.File;
import java.io.FileReader;
import java.io.Reader;

class FileReaderDemo {
    public static void main(String args[]) throws Exception {
        File f = new File("files/TestFile.txt");
        Reader fr = new FileReader(f);//etay oshob available method nai
        char data[] = new char[(int) f.length()];//jhamela hote pare what if 1 char != 1 byte....encoding e jhamela hole emon hotei pare
        fr.read(data);//read aager motoi pray....just ekhon koyta character porse gune...rather than byte koyta
        System.out.println(new String(data));
        //better practice
//        char data2[] =new char[1024];
//        int charsread;
//        while((charsread=fr.read(data2))!=-1){
//            System.out.println(new String(data2,0,charsread));
//        }
        fr.close();
    }
}