interface Alpha 
{
    default void reset() {
        System.out.println("Alpha's reset");
    }
}

interface Beta extends Alpha
{
    default void reset() {
        System.out.println("Beta's reset");
        Alpha.super.reset();
    }
}
public class InterfaceMultipleInheritanceTest implements Alpha, Beta {

    public void reset() {
        System.out.println("My reset");
         Beta.super.reset();
        //Alpha.super.reset(); //eta korte parbona karon Alpha ke already Beta extend kortese eta redundant hoye jay
    }

    public static void main(String[] args) {
        InterfaceMultipleInheritanceTest i = new InterfaceMultipleInheritanceTest();
        i.reset();
    }
}
