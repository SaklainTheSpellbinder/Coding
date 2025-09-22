package Jhamela;

import java.lang.classfile.constantpool.PoolEntry;

interface Artist{
    default void work(){
        System.out.println("Painting a masterpiece");
    }
}

interface Programmer{
    default void work(){
        System.out.println("Writing elegant code...");
    }
}

class GameDeveloper implements Artist, Programmer{
    @Override
    public void work(){
        System.out.println("Inside GameDeveloper");
        Artist.super.work();
        Programmer.super.work();
    }
}

public class DefaultNiyeMaramari {
    public static void main(String[] args){
        GameDeveloper dev=new GameDeveloper();
        dev.work();
    }
}
