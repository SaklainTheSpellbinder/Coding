package collections;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.stream.Collectors;

public class ArrayListDemo2 {

    public static void main(String args[]) {
        // create an array list
        List<Integer> al = new ArrayList<>();
        System.out.println("Initial size of al: " + al.size());

        // add elements to the array list
        al.add(10);
        al.add(20);
        al.add(30);
        al.add(40);
        al.add(50);

        Iterator<Integer> itr=al.iterator();
        while(itr.hasNext()){
            System.out.print(itr.next()+" ");
        }
        System.out.println();

        // foreach iterate
        for (Integer i : al) {
            System.out.print(i + " ");
        }
        System.out.println();

        al.remove(2); // remove using index
        al.remove(Integer.valueOf(40));//eta hocche 40 value ke remove korbe

        for (Integer i : al) {
            System.out.print(i + " ");
        }
        System.out.println();

        Integer x=50;
        al.remove(x);//eta 50 value remove korbe


        // convert to array
        Integer[] ia = new Integer[al.size()];
        al.toArray(ia);
        Integer[] ba=al.toArray(new Integer[0]);

        for (Integer i : ba) {
            System.out.print(i+" ");
        }
        System.out.println();

        // iterate array
        for (int i = 0; i < ia.length; i++) {
            System.out.print(ia[i] + " ");
        }
        System.out.println();

        // convert array to list
        List<Integer> alist = Arrays.asList(ia);         //ekhane jet list toiri hoy eta immutable....just read only...remove add kora jabe na
        //alist.add(2);  eta runtime error dibe....compile time na

        // foreach iterate
        for (Integer i : alist) {
            System.out.print(i + " ");
            i++;
            System.out.print("("+i+" : changed value...but list e to for each loop e change kora jayna.....and eta emneo immutable list) ");
        }
        System.out.println();


        //alist.remove(2); //abstract list theke remove runtime error dey
        for (Integer i : alist) {
            System.out.print(i + " ");
        }
        System.out.println();

        for (Integer i : al) {
            System.out.print(i + " ");
        }
        System.out.println();

        //streams         //map filter collect
        List<Integer> streamList=Arrays.stream(ia).collect(Collectors.toList());
        streamList.forEach(e-> System.out.print(e+ " "));
        System.out.println();

        //primitive type array to list
        int [] a={10,20,30,40,50};
        List<Integer> integerList=Arrays.stream(a).boxed().collect(Collectors.toList());
        integerList.forEach(e-> System.out.print(e+ " "));
        System.out.println();

    }
}