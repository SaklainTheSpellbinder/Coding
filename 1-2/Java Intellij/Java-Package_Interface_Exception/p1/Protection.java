package p1;

public class Protection {
    int n = 1;
    private int nPrivate = 2;
    protected int nProtected = 3;
    public int nPublic = 4;

    void showTintin(){
        System.out.println("Guys i'm in showTintin() method of Protection class");
        Tingtong oi=new Tingtong();
        System.out.println(oi.a+" Hey it's 'a' from the Tintin inner private class....cool eh?");
        System.out.println((oi.b +" wow b of Tintin is also accessible here"));
        System.out.println(oi.c + " Orreh c of Tintin is also accessible here");
    }

    private class Tintin {
        public int a=1;
        protected int b=4;
        private int c=5;
    }

    protected class Tingtong {
        public int a=1;
        protected int b=4;
        private int c=5;
    }


    public Protection() {
        System.out.println("---Protection---");
        System.out.println(n);
        System.out.println(nPrivate);
        System.out.println(nProtected);
        System.out.println(nPublic);
        showTintin();
    }
}
