package slideB;

public class Sony extends Company{
    @Override
    public int price() {
        return 20;
    }

    @Override
    public String pack() {
        return "Sony CD";
    }
}

class Samsung extends Company{
    @Override
    public int price() {
        return 15;
    }

    @Override
    public String pack() {
        return "Samsung CD";
    }
}
