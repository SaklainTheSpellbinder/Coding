package collections;

import java.util.ArrayList;
import java.util.List;

public class ArrayListDemo1 {

    public static void main(String args[]) {
        // create an array list
        List<String> al = new ArrayList<>();//non synchronized eta.....stringbuilder er moto
        System.out.println("Initial size of al: " + al.size());

        // add elements to the array list
        al.add("C");
        al.add("A");
        al.add("E");
        al.add("B");
        al.add("D");
        al.add("F");
        al.add(1, "X");//add kore onnoguloke shift kore dibe
        al.set(3,"tintin");//change kore value //idx ultapalta dile ArrayIndexOutOfBoundsException

        System.out.println("Size of al after additions: " + al.size());

        // display the array list
        System.out.println("Contents of al: " + al);
        for (int i = 0; i < al.size(); i++) {
            System.out.print(al.get(i) + "  ");
        }
        System.out.println("");

        // Remove elements from the array list
        al.remove("F");
        al.remove(2);//remove korte parle okay...na korte parle no error....jeta remove kore oita return kore idolo
        al.remove("tintin");

        System.out.println("Size of al after deletions: " + al.size());
        System.out.println("Contents of al: " + al);

        al.forEach(e -> System.out.println(e));

        List al2=new ArrayList();//type safe na but ja iccha rakha jay rki...but use korte hole to typecast kore newa lagbe
        al2.add("Saklain");
        al2.add(3);
        al2.add(new Thread());
        String s=(String)al2.get(0);//jehetu ja iccha boshaisi tai ekhon emne object er moto hoye geche so amader type cast kora lagbe
        System.out.println(s);
    }
}