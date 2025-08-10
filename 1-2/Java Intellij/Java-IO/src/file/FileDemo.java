package file;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.sql.SQLOutput;
import java.util.Arrays;
import java.util.Date;

class FileDemo {

    static void p(String s) {
        System.out.println(s);
    }

    public static void main(String args[]) throws IOException {
        File f1 = new File("src/files/dir/sample.txt");
        File f2=new File("src/files/src.mp4");
        p("File Name: " + f1.getName());
        p("Path: " + f1.getPath());
        p("Abs Path: " + f1.getAbsolutePath());
        p("Parent: " + f1.getParent());
        p(f1.exists() ? "exists" : "does not exist");
        p(f1.canWrite() ? "is writeable" : "is not writeable");
        p(f1.canRead() ? "is readable" : "is not readable");
        p("is " + (f1.isDirectory() ? "a directory" : "not" + " a directory"));
        p(f1.isFile() ? "is normal file" : "not a normal file");
        p("File last modified: " + f1.lastModified());
        Date date = new Date(f1.lastModified());
        p(date.toString());
        Date dt = new Date();
        p("Current Date: " + dt.toString());
        p("File size: " + f1.length() + " Bytes");//eta mainly koto byte eta return kore but jodi exist ee na kore tahole 0L return kore
        //f1.delete();
        //f1.mkdir();
        //f1.mkdirs();
        p(Arrays.toString(f1.list()));
        p(f2.exists()?"exists":"doesn't exist");
        p(f2.isFile()?"is a file":"not a file");
        p(f2.canRead()?"is readabble":"is not readable");
        p(f2.canWrite()?"is writable": "is not writable");

        File f3=new File("src/files/hehe.txt");
        if(f3.createNewFile()){
            System.out.println("hoise");
        }
        else{
            System.out.println("aage thekei ache");
        }

        FileWriter writer=new FileWriter(f3,true);
        writer.write("Back to porashona\n");
        writer.write("Studying \n");//nijer theke newline dewa laage
        writer.close();

        File f4=new File("src/tintin");
        p(f4.exists()?"exists":"doesn't exist");
        p(f4.isDirectory()?"is a directory":"not a tintin lover");//jei jinish exist ee kore na oita directory kina check korle false ee ashbe
        f4.mkdirs();//eta boolean return kore and also eta necessary shob parent folder o banay ashe ja path e ache....and only eta hole o true dey(parent aage theke banano thakle pera nai...mainly last dir ta o nije banay kina check kore....)....nahoy false return kore
        p(f4.isDirectory()?"is a directory":"not a tintin lover");
        File f5=new File(f4,"cuteTintin.txt");
        if(f5.createNewFile()){
            System.out.println("cute tintin file successfully created");
        }
        else{
            System.out.println("mara kha");
        }
        FileWriter writer2=new FileWriter(f5,true);
        writer2.write("Hey tintin, kemon acho tumi?? tf e mara khawar prep kotodur?\n");
        writer2.write("ten thousand thunderous typhoon");
        writer2.close();
        File f6=new File("src");
        System.out.println(Arrays.toString(f6.list()));//eta khali dir or file er name er string er array return kore...and jehetu array er kono toString alada kore nai....tai Arrays.toString() use kora laage just print dile hashcode print hobe
        System.out.println(Arrays.toString(f6.listFiles()));//getpath er moto string er array return kore....
    }
}