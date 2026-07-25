package slideB;

public abstract class CD implements Packing {
    public abstract String pack();
}

abstract class Company extends CD{
    public abstract int price();
}


