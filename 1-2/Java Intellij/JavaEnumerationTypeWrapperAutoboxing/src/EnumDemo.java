
enum Apple {
    Jonathan, GoldenDel, RedDel, Winesap, Cortland//eder type mainly ei enum Apple ta ee....self typed
}

public class EnumDemo {
    public static void main(String args[]) {
        Apple ap;
        ap = Apple.RedDel;
        System.out.println("Value of ap: " + ap);
        System.out.println();
        System.out.println(Apple.Cortland);//evabeo print kora jay name
        ap = Apple.GoldenDel;
        if (ap == Apple.GoldenDel)
            System.out.println("ap contains GoldenDel.\n");
        switch (ap) {
            case Apple.Jonathan://complete reference e lekha etay emon likhle compilation error howar kotha....jodio hoyni rki
                System.out.println("Jonathan is red.");
                break;
            case GoldenDel:
                System.out.println("Golden Delicious is yellow.");
                break;
            case RedDel:
                System.out.println("Red Delicious is red.");
                 break;
            case Winesap:
                System.out.println("Winesap is red.");
                break;
            case Cortland:
                System.out.println("Cortland is red.");
                break;
        }
    }
}
