package threads;

import java.util.Scanner;

public class CreateThread  {
    public static void main(String[] args) {
        CreateThread ct = new CreateThread();
        new Thread(CreateThread::f2, "T3").start();
        Thread t=new Thread(ct::f1, "T1");
        t.start();
        new Thread(CreateThread::f3,"T4").start();
    }
    //basically the fact is jokhon kono object er kono method er upor lock boshano hoy....
    //tokhon kono thread oi lock e dhuklkle onno kono thread oi method to doorer kotha oi object er onnanno synchronized method gulo teo dhukte pare na....
    //karon ekta object er ektai monitor ache
    //but static method er upor synchronized boshale oita cholte parbe...karon eta to object er upor depend kore na
    //eki class er 2 ta synchronized static thakle lock hobe static der moddhe..ekta shesh howa na porjonto onnota cholbe na...but etar shate abar non static der kono relation nai

    synchronized public void f1() {
        for (int i = 10; i > 0; i--) {
            System.out.println("f1(): " + i + " " + Thread.currentThread().getName());
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }

    Scanner sc=new Scanner(System.in);

    synchronized public static void f2() {
        for (int i = 10; i > 0; i--) {
            System.out.println("f2(): " + i + " " + Thread.currentThread().getName());
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }

    synchronized public static void f3() {
        for (int i = 10; i > 0; i--) {
            System.out.println("f3(): " + i + " " + Thread.currentThread().getName());
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }

}
