package bytestream;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class ChangingOutputStream {
    public static void main(String[] args) throws FileNotFoundException {
        int[] a={1,2,3,4,56,7,8,8,8,8,88,8,8};
        //List<Integer> l= new ArrayList<>(Arrays.asList(a)); //int er kono list possible na

        Integer[] b={2,3,54,5,6,6,3,2,2,3,3,34,44,443,4};
        //ArrayList<Integer>l2=(ArrayList<Integer>) Arrays.asList(b);//typecast kroleo hobe na....List hocche parent class of ArrayList down casting to hoyna....runtime error
        ArrayList<Integer>l3=new ArrayList<>(Arrays.asList(b));//constructor ache emon....but raw array r constructor nei....pocha java
        //use java , be relaxed here we gooooooooooooooooooooooooo

        System.out.println(l3);

        PrintStream originalout=System.out;
        System.setOut(new PrintStream(new FileOutputStream("src/output.txt",true)));//na thakle nije create kore ney//append o kora jay yaaaayyyyyyyyyyyyyyyyyyyyyyyyyyyy
        System.out.println("hehehehehehehehe");
        System.out.println("Amar nam tintin");
        System.setOut(originalout);
        System.out.println("Abar ashilam fire dhanshiritir teere, hoyto manush noy console io hishebe.... :(");

        String[][] h={{"hi","Hello!"},{"tin","tintin"}};
        System.out.println(h);
        System.out.println(Arrays.toString(h));
        System.out.println(Arrays.deepToString(h)); //eta use korte hoy 2d r jonno
    }
}
