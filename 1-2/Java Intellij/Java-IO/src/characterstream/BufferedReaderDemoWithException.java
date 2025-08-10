package characterstream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

class BufferedReaderDemoWithException {
    public static void main(String args[]) {
//        BufferedReader br = null;
//        try {
//            br = new BufferedReader(new FileReader("TestFile.txt"));
//            while (true) {
//                String s = br.readLine();
//                if (s == null) break;
//                System.out.println(s);
//            }
//        } catch(IOException e) {
//            e.printStackTrace(); // er mane eta hocche khulte parenai maybe or something
//        } finally {
//            try {
//                if (br != null)
//                    br.close(); //jodi khule thake tahole close kore...but close nijeo exception dite pare...tai etao catch kora lagbe....checked exception
//            } catch (IOException e) {
//                throw new RuntimeException(e);
//            }
//
//        }

        try ( BufferedReader br = new BufferedReader(new FileReader("files/TestFile.txt"))  ) {
            while (true) {
                String s = br.readLine();
                if (s == null) break;
                System.out.println(s);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        System.out.println("ekhono beche achi");

        try (
            BufferedReader br = new BufferedReader(new FileReader("src/files/TestFile.txt"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("src/Files/TestFile2.txt"))         //erokom korle r close kora lage na eta auto hoy....java etto bhaloo
            ) {
            while (true) {
                String s = br.readLine();
                if (s == null) break;
                bw.write(s);
                bw.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}