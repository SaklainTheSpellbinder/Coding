// Use an enum constructor, instance variable, and method.
enum AppleNew {
    Jonathan(10), GoldenDel(9), RedDel(12), Winesap(15), Cortland(8);
//ekhane konotay constructor na dile hobe na
    //tobe default constructor overload korle hobe
    private int price; // price of each apple

    // private constructor
    AppleNew(int p) {
        price = p;
    }

    int getPrice() {
        return price;
    }

    void setPrice(int price) {
        this.price = price;
    }

//    @Override
//    public String toString() {
//        return "AppleNew {price=" + price + "}";
//    }
}

public class EnumDemo3 {

    public static void print(AppleNew appleNew) {
        System.out.println(appleNew);
    }
    public static void main(String args[]) {
        // Display price of Winesap.
        AppleNew b=AppleNew.Jonathan;  //constructor type kore bracket diye call kora jayna...and b ke initialize na kore price dekhte gele compiletime error
        System.out.println(b+" costs "+b.getPrice());
        System.out.println("Winesap costs " +
                AppleNew.Winesap.getPrice() +
                " cents.\n");
        // Display all apples and prices.
        System.out.println("All apple prices:");
        for (AppleNew a : AppleNew.values()) {
            if(a==AppleNew.GoldenDel){
                a.setPrice(40);
            }
            System.out.println(a + " costs " + a.getPrice() +
                    " cents.");
        }
        System.out.println(AppleNew.Winesap.getPrice());
        AppleNew.Winesap.setPrice(100);
        System.out.println(AppleNew.Winesap.getPrice());
        print(AppleNew.Winesap);
    }
}