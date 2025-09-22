public class ForEachTest {
    public static void main(String[] args) {
        int numbers[] = {1, 2, 3, 4, 5};
        for (int x : numbers) {
            System.out.print(x + " ");
            x = x * 10; // no effect on numbers
        }
        System.out.println();

        int numbers2[][] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        for (int[] x : numbers2) { //x e change korle real change hobe karon eta reference nicche
            for (int y : x) {//ekhane y e change korleo eta main number2 array te kono change korte parbe na(karon y just copy of value).......but jodi amra emon kori je....x[0]=89; ebhabe korle main tay change
                System.out.print(y + " ");
            }
            System.out.println("");
        }

        for (int[] x : numbers2) {
            for(int i=0;i<x.length;i++){
                x[i]=99;//ekhane main tay change hobe
            }
        }

        for (int[] x : numbers2) {
            for (int y : x) {//ekhane y e change korleo eta main number2 array te kono change korte parbe na(karon y just copy of value).......but jodi amra emon kori je....x[0]=89; ebhabe korle main tay change
                System.out.print(y + " ");
            }
            System.out.println("");
        }
    }
}
