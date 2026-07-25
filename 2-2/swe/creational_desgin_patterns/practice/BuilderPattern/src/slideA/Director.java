package slideA;

public class Director {
    public void construct(IBuilder builder){
        builder.buildBody();
        builder.insertWHeels();
        builder.addHeadLights();
    }
}


