package others;

import java.io.RandomAccessFile;

public class MemoryVault {
    public static void main(String[] args) throws Exception {
        RandomAccessFile vault = new RandomAccessFile("src/memories.txt", "rw");

        vault.seek(0);
        vault.write("Rain-soaked football\n".getBytes());

        vault.seek(100);
        vault.write("Moonlit rooftop \n".getBytes());

        vault.seek(200);
        vault.write("Maramari\n".getBytes());

        System.out.println("Memory 1:");
        vault.seek(0);
        System.out.println(vault.readLine());

        System.out.println("\nMemory 2:");
        vault.seek(100);
        System.out.println(vault.readLine());

        System.out.println("\nMemory 3:");
        vault.seek(200);
        System.out.println(vault.readLine());

        vault.close();
    }
}