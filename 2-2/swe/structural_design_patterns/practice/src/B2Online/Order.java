package B2Online;
import java.util.ArrayList;
import java.util.List;

interface OrderItem{
    public double getPrice();
    public void print(String s);
}

class Food implements OrderItem {
    private final String name;
    private final double value;

    Food(String name, double value) {
        this.name = name;
        this.value = value;
    }

    @Override
    public double getPrice() {
        return value;
    }

    @Override
    public void print(String indent) {
        System.out.printf("%s- %s: %.2f%n", indent, name, value);
    }
}

class SetMenu implements OrderItem {
    private final String name;
    private final List<Food> children = new ArrayList<>();

    SetMenu(String name) {
        this.name = name;
    }

    public void addFood(Food component) {
        if (component == null) {
            throw new IllegalArgumentException("Child cannot be null");
        }
        children.add(component);
    }

    public void remove(Food component) {
        children.remove(component);
    }

    @Override
    public double getPrice() {
        double total = 0;
        for (Food child : children) {
            total += child.getPrice();
        }
        return total*0.90;
    }

    @Override
    public void print(String indent) {
        System.out.println(indent + "+ " + name);
        for (Food child : children) {
            child.print(indent + "    ");
        }
        System.out.printf("%s  Total: %.2f%n", indent, getPrice());
    }
}

interface OnlyGroceryStuff extends OrderItem {

}

class Grocery implements OnlyGroceryStuff {
    private final String name;
    private final double price;

    Grocery(String name, double value) {
        this.name = name;
        this.price = value;
    }

    @Override
    public double getPrice() {
        return price;
    }

    @Override
    public void print(String indent) {
        System.out.printf("%s- %s: %.2f%n", indent, name, price);
    }
}



class GroceryPackage implements OnlyGroceryStuff {
    private final String name;
    private final List<OnlyGroceryStuff> children = new ArrayList<>();

    GroceryPackage(String name) {
        this.name = name;
    }

    public void add(OnlyGroceryStuff component) {
        if (component == null) {
            throw new IllegalArgumentException("Child cannot be null");
        }
        children.add(component);
    }

    public void remove(OnlyGroceryStuff component) {
        children.remove(component);
    }

    @Override
    public double getPrice() {
        double total = 0;
        for (OnlyGroceryStuff child : children) {
            total += child.getPrice();
        }
        return total;
    }

    @Override
    public void print(String indent) {
        System.out.println(indent + "+ " + name);
        for (OnlyGroceryStuff child : children) {
            child.print(indent + "    ");
        }
        System.out.printf("%s  Total: %.2f%n", indent, getPrice());
    }
}



public class Order {
    private List<OrderItem> items = new ArrayList<>();
    public void add(OrderItem item) {
        items.add(item);
    }
    public double getTotalPrice() {
        double total = 0;
        for (OrderItem item : items) {
            total += item.getPrice();
        }
        return total;
    }
    public void printReceipt() {
        System.out.println("========== RECEIPT ==========");
        for (OrderItem item : items) {
            item.print("");
        }
        System.out.println("-----------------------------");
        System.out.printf("Total Bill: £%.2f%n", getTotalPrice());
    }
}