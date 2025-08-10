package generics;

public class GenObject {
    private Object a;

    public void setObj(Object a) {
        this.a = a;
    }

    public Object getObj() {
        return this.a;
    }

    public static void main(String[] args) {
        GenObject genObject = new GenObject();
        //genObject.setObj("Hello");
        //genObject.setObj(10);
        //genObject.setObj(new Thread());
        System.out.println(genObject.getObj());//kichu na set korle null print hobe...obvious
        String s = (String) genObject.getObj();//jodi aage kichu set na kora hoye thake tahole to null ee assign hobe string s e....null pointer exception hoyna typecast er jonno
        //ultapalta type cast korle ClassCastException dey
        System.out.println(s);
    }
}


