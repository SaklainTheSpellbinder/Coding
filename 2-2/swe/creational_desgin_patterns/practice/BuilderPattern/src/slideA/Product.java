import java.util.LinkedList;

public class Product {
    private final LinkedList<String> parts=new LinkedList<>();

    public void add(String part){
        parts.addLast(part);
    }

    public void show(){
        System.out.println("\nProduct completed as below:");
        for (String part: parts){
            System.out.println(part);
        }
    }

    


}
