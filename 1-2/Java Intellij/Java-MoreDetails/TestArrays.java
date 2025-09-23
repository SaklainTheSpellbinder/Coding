
public class TestArrays {

    public static void changeString(String a){
        a="NameeeeeeeeeeeeeeeeeeeeeeeeeeChanged Maybe???";//ei change baire visible hobe na....karon ekhon ei a reference ta just aager copy howa b er reference na hoye change hoye notun reference hoye geche that's it...aager tar kono change hoyni....hehehehehehehe
        //shudu string na emon Integer, Double eshob typewrapper use holeo hoto...java te shudu pass by value hoy(reference type er khetre reference er value copy hoy rki) so ekhon as a result change hoye notun reference e point kore ei local variable...but main tar no change
        a=new String("pintintintint");//new korleo hobe na....same kaj ee to maybe...eta to r o beshi hobe na
    }

    public static void chaneprimitive(int a){
        a=99;//eita o hobe na...primitive e to just value copy hoy reference o na....eta to ekdom ee howar kotha na
    }

    public static void main(String[] args){
        int[] arr;
        arr=new int[5];
        arr=new int[]{1,2,3,4,5}; //ba ebhabeo lekha jabe...//aager line jodi comment na o kora hoy notun kore ei reference er jonno notun memory store hobe rki....aager gulo garbage collector bhai dekhe nibe
        //arr={1,2,3,4,5,6};//eta possible na kintu........... aager line er moto korte hobe or loop
        for(int i=0;i<arr.length;i++){
            System.out.println(arr[i]);
        }
        System.out.println("tintintintintintintitnitntintin");
        int arr2[];
        arr2=new int[6];
        for(int i=0;i<arr2.length;i++){
            System.out.println(arr2[i]);//null diye already initialize kore felse java
        }

        String b="TingTong";
        changeString(b);
        System.out.println(b);

        int tintintintinitn=43;
        chaneprimitive(tintintintinitn);
        System.out.println(tintintintinitn);//same 43 ee print hobe...change hobe na

        Runnable[] tasks=new Runnable[3];
        tasks[0]=new Thread(()->{
            for(int i=0;i<10;i++){
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                System.out.println("run");
            }
        });
//        Thread a=(Thread)tasks[0];
//        a.start();
        ((Thread)tasks[0]).start();
        tasks[1]=()-> System.out.println("tintnitnitnitnitntintintintinin ami ekta lamba diye banano anonymous thread....yaayyyyyyyyyyy");
        tasks[1].run();//kintu thread staart na kore run kore dekhi kemon laage
        Thread t=new Thread(()-> System.out.println("mara kahbe saklain"));
        t.run();//eta main thread e cholbe
        t.start();//eta new thread e cholbe
    }
}

