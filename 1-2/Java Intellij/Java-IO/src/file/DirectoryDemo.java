package file;
import java.io.File;

class DirectoryDemo {

    public static void visitDir(File f) {
        if (f.isDirectory()) {
            File[] s = f.listFiles();
            if (s != null) {
                for (File file : s) {
                    System.out.println(file);
                    if (file.isDirectory()) {
                        visitDir(file);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        String dirname = "src/files/dir";
        File f = new File(dirname);
        visitDir(f);
    }
}
