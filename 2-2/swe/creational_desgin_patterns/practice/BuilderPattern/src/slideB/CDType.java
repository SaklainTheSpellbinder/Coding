package slideB;
import java.util.ArrayList;
import java.util.List;

public class CDType {
    private final List<Packing> items=new ArrayList<>();

    public void addItem(Packing packs){
        items.add(packs);
    }

    public void showItems(){
        for(Packing packing: items){
            System.out.print("CD Name: " + packing.pack());
            System.out.println(", Price: " + packing.price());
        }
    }
}
