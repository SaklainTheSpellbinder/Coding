package generics;

public class MyGenerics1<T> {
    private T a;
    //no static method possible using class's type parameter but static method possible with own type parameters

    public MyGenerics1(){

    }

    public MyGenerics1(T i) {
        a=i;
    }

    public void setObj(T a) {
        this.a = a;
    }

    public T getObj() {
        return this.a;
    }

    public void showType(){
        System.out.println("Type is : "+a.getClass().getName());
    }

    public static void main(String[] args) {
        MyGenerics1<Integer> myGenerics = new MyGenerics1<>();//can't use primitive type....only reference type is possible
        myGenerics.setObj(10);
        System.out.println(myGenerics.getObj());
        MyGenerics1<String> myGenerics1 = new MyGenerics1<>();
        myGenerics1.setObj("Hello");
        String str = myGenerics1.getObj();
        System.out.println(str);
        MyGenerics1 noGenerics = new MyGenerics1(); // still possible
        noGenerics.setObj(20);
        System.out.println(noGenerics.getObj());
        noGenerics.setObj("World");
        System.out.println(noGenerics.getObj());
        MyGenerics1[] mygenrics1=new MyGenerics1[10];//emon raw array ee possible generics diye....type bole diye array possible na....
        mygenrics1[0]=new MyGenerics1<Integer>(10);
        mygenrics1[1]=new MyGenerics1<String>("Saklain");//ekek index e ekek object possible
        mygenrics1[2]=new MyGenerics1<Thread>(new Thread());
        for(int i=0;i<3;i++){
            System.out.println(mygenrics1[i].getObj());
        }
        MyGenerics1<Integer>[] arr = new MyGenerics1[10];//possible with warning
        //arr[0].showType();//ekhane dile to null pointer exception ashbe
        arr[0]=new MyGenerics1<Integer>(10);
        arr[0].showType();//java.lang.Integer print hobe
        //arr[1]=new MyGenerics1<String>("Hello");//possible na incompatible type....compile time error
        //MyGenerics1<Integer>[] arr = new MyGenerics1<Integer>[10]; // Compile-time error
        //a generic thingy can't extend throwable class
        //generics in java are erased at runtime(called type erasure)
        //the compiler treats raw type as if all generics are just Object

    }
}


