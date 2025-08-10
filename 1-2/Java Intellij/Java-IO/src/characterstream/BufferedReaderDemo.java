package characterstream;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.Reader;

class BufferedReaderDemo {
    public static void main(String args[]) throws Exception {
        Reader fr = new FileReader("files/TestFile.txt");
        BufferedReader br = new BufferedReader(fr);
        while (true) {
            String s = br.readLine();
            if (s == null) break;
            System.out.println(s);
        }
        br.close();
        fr.close();
        //era ekta large chunk(8 kb types) of memory aage thekei niye fele then amra okhan thekei mainly read kori.....ete proti muhurte disk e read kora lagtese na
    }
}