class AA {
    private int a;

    public AA() {
        a = 10;
    }

    public int getA() {
        return a;
    }

    public void setA(int a) {
        this.a = a;
    }

    public void printClass() {
        System.out.println("AA"+a);
    }
}

class BB extends AA {
    private int b;

    public BB() {
        b = 20;
    }

    public int getB() {
        return b;
    }

    public void setB(int b) {
        this.b = b;
    }

    @Override
    public void printClass() {
        System.out.println("BB"+b);
    }
}

class CC extends BB {
    private int c;

    public CC() {
        c = 30;
    }

    public int getC() {
        return c;
    }

    public void setC(int c) {
        this.c = c;
    }

    @Override
    public void printClass() {
        System.out.println("CC"+c);
    }
}

public class InheritanceVarDemo {
    static AA getObject(int type) {
        switch (type) {
            case 0:
                return new AA();
            case 1:
                return new BB();
            case 2:
                return new CC();
            default:
                return null;
        }
    }

    public static void main(String[] args) {
        var a = new AA();
        var b = new BB();
        var c = new CC();
        var r = a;
        r.printClass(); // AA
        r = b;
        r.printClass(); // BB
        r = c;
        r.printClass(); // CC

        var x = getObject(0);//jehetu AA return kore getObject func....tai etar type AA ee hoy....3 ta ee x,y,x shob AA
        var y = getObject(1);
        var z = getObject(2);

        System.out.println(x.getA());
        System.out.println(y.getA()); // getB file Error, type of y is AA
        System.out.println(z.getA()); // getC dile Error, type of z is AA //o child er method to dekhte parbe na but child er override kora method dekhte parbe btw
        x.printClass();//AA er printclass hobe
        y.printClass();//BB er printclass ee hobe.....supercalss instance diye subclass er override kora jinish print kora jay
        z.printClass();//CC er printclass ee hobe.....supercalss instance diye subclass er override kora jinish print kora jay
        
    }
}
