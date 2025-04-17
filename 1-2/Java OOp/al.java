import java.util.ArrayList;
import java.util.Comparator;

public class al{
    public static void main(String[] args){
        ArrayList<Integer>number= new ArrayList<>();


        //int double float boolean
        //Integer is a refernce type for int....-> int wrapper class is Integer
        //same way te -> Integer Double Float Boolean  egula ache..ache.egula shob wrapper class

        number.add(1);
        number.add(2);
        number.add(3);
        number.add(4);
        number.add(5);


        System.out.println(number.toString());
        System.out.println(number.get(2));

        number.remove(2);
        System.out.println(number.toString());

        number.remove(Integer.valueOf(4));
        System.out.println(number.toString());

        number.set(2,30);//number.set(2,Integer.valueOf(30));
        System.out.println(number.toString());

        number.add(4);
        number.add(-1);

        number.sort(Comparator.naturalOrder());
        System.out.println(number.toString());

        number.sort(Comparator.reverseOrder());
        System.out.println(number.toString());

        System.out.println(number.size());

        //System.out.println(number.contains(Integer.valueOf(-1)));

        System.out.println("before: "+ number.toString());

        number.forEach(it ->{
            number.set(number.indexOf(it),it*2);
            //System.out.println(it*2);//doesn't change the real arraylist
        });

        System.out.println("after: "+ number.toString());


        number.clear();
        System.out.println(number.toString());

        System.out.println(number.isEmpty());

    }
}