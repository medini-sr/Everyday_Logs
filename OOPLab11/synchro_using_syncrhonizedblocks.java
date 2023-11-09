class SynchronizedBlocksDemo {
    private int count = 0;
    private Object lock = new Object();

    public void increment() {
        synchronized (lock) {
            count++;
        }
    }

    public int getCount() {
        synchronized (lock) {
            return count;
        }
    }
}

class ThreadC extends Thread {
    private SynchronizedBlocksDemo demo;

    public ThreadC(SynchronizedBlocksDemo demo) {
        this.demo = demo;
    }

    public void run() {
        for (int i = 0; i < 10000; i++) {
            demo.increment();
        }
    }
}

class ThreadD extends Thread {
    private SynchronizedBlocksDemo demo;

    public ThreadD(SynchronizedBlocksDemo demo) {
        this.demo = demo;
    }

    public void run() {
        for (int i = 0; i < 10000; i++) {
            demo.increment();
        }
    }
}

public class SynchronizeBlocksDemo {
    public static void main(String[] args) throws InterruptedException {
        SynchronizedBlocksDemo demo = new SynchronizedBlocksDemo();

        ThreadC threadC = new ThreadC(demo);
        ThreadD threadD = new ThreadD(demo);

        threadC.start();
        threadD.start();

        threadC.join();
        threadD.join();

        System.out.println("Count: " + demo.getCount());
    }
}
