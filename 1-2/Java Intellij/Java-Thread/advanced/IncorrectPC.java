package advanced;

class Buffer {
    int value;
    volatile boolean valueset=false;
    synchronized  int consume() {
        while(!valueset){
            try {
                wait();
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
        valueset=false;
        notifyAll();
        System.out.println(Thread.currentThread().getName() + " consumes: " + value);
        return value;
    }

    synchronized void produce(int value) {
        while(valueset){
            try {
                wait();
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
        valueset=true;
        notifyAll();
        this.value = value;
        System.out.println(Thread.currentThread().getName() + " produces: " + this.value);
    }
}

class Producer implements Runnable {
    Buffer buffer;

    Producer(Buffer buffer, String name) {
        this.buffer = buffer;
        new Thread(this, name).start();
    }

    public void run() {
        int i = 0;
        while (i < 100) {
            buffer.produce(i++);
            // try {
            //     Thread.sleep(2000);
            // } catch (InterruptedException e) {
            //     throw new RuntimeException(e);
            // }
        }
    }
}

class Consumer implements Runnable {
    Buffer buffer;

    Consumer(Buffer buffer, String name) {
        this.buffer = buffer;
        new Thread(this, name).start();
    }

    public void run() {
        int i = 0;
        while (i++ < 100) {
            buffer.consume();
            // try {
            //     Thread.sleep(1000);
            // } catch (InterruptedException e) {
            //     throw new RuntimeException(e);
            // }
        }
    }
}

public class IncorrectPC {
    public static void main(String[] args) {
        Buffer buffer = new Buffer();
        new Producer(buffer, "Producer");
        new Consumer(buffer, "Consumer");
        System.out.println("Press Control-advanced.C to stop.");
    }
}
