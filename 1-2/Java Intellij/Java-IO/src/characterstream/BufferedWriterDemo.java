package characterstream;
import java.io.*;

class BufferedWriterDemo {
    public static void main(String args[]) throws Exception {
        FileReader fr = new FileReader("src/files/TestFile.txt");
        BufferedReader br = new BufferedReader(fr);
        FileWriter fw = new FileWriter("src/files/TestFileCopy.txt");
        BufferedWriter bw = new BufferedWriter(fw);
        while (true) {
            String s = br.readLine();
            if (s == null) break;
            bw.write(s);
            bw.newLine();//new line nijer dewa laage///eta filewriter e dewa jayna
            Thread.sleep(1000);//eta diyei check kora jay thread sleep koray
        }
        //mainly bufferedwriter ekta buffer e joma rakhe data....shate shate file e likhe na....karon always disk e lekha onek time and memory and onek costly so bufferedreader egulo buffer e rakhe.....but eta full hoye gele
        //tokhon eta ke buffered writer file e likhe dey.....loop e je proti line tokhon ee file e likhtese emon na...koekline joma hoise....then likhe fele emon mainly....but last e buffer e jeta thake buffer full na holeo tokhon to likhbe na...tai flush kora uchit...jodio close method internally flush kore dey...so pera nai
        bw.close();
        fw.close();
        br.close();
        fr.close();
    }
}