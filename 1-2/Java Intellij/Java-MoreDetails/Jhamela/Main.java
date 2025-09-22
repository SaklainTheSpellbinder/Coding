package Jhamela;

interface Speaker{
    default void speak(){
        System.out.println("speaking from the speaker interface");
    }
}

class Person{
    public void speak(){
        System.out.println("Speaking from the person class");
    }
}

class Lecturer extends Person implements Speaker{
    public void giveLecture(){
        super.speak(); //eta ei class er super class ke daake maane Person er speak() ke
        Speaker.super.speak(); //eta Speaker interface er speak() ta call kore
    }
}

public class Main {
    public static  void main(String[] args){
        Lecturer lecturer=new Lecturer();
        lecturer.giveLecture();
    }
}
