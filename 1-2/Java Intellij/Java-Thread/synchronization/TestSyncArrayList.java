package synchronization;

import java.util.ArrayList;
import java.util.List;

class MyThread implements Runnable {
    List<String> list;
    Thread t;

    public MyThread(List<String> list) {
        this.list = list;
        t = new Thread(this);
        t.start();
    }

    public void run() {//ekhane synchronized diye labh nai....eta hocche this objecg ke lock kore....but 2 ta thread to duita alada object so eder run o alada....but oije share er jonno jei object ta pathacchi...oder vitor o alada object chilo but oita to amara same ta ee assign korsi constructor e....tai rki eta hobe
        for (int i = 1; i <= 10000; i++) 
        {
            list.add(String.valueOf(i));
//            synchronized(list)
//            {
//                list.add(String.valueOf(i));
//            }
        }
    }
}

public class TestSyncArrayList {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
        MyThread myThread1 = new MyThread(list);
        MyThread myThread2 = new MyThread(list);
        try {
            myThread1.t.join();
            myThread2.t.join();
        } catch (Exception e) {
            System.out.println(e);
        }
        System.out.println(list.size());
    }
}
//The sun rises and sets with her

//Her laughter, soft as summer rain,
//Awakes the petals, soothes the pain,
//Her silence holds a gentle ache,
//Like twilight on a silver lake.