public class tintin {
    static int divide(){
        int d=0;
        int a=10/d;
        return a;
    }
    public static void main(String[] args) {
        try{
            System.out.println(tintin.divide());
        }
        catch(RuntimeException e){
            System.out.println("Caught exception: "+e);
        }
        System.out.println("after catch");
    }
}
