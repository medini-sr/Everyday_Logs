class SynchronizedMethodsDemo {
    private int count = 0;

    public synchronized void increment() {
        count++;
    }

    public synchronized int getCount() {
        return count;
    }
}

class ThreadA extends Thread {
    private SynchronizedMethodsDemo demo;

    public ThreadA(SynchronizedMethodsDemo demo) {
        this.demo = demo;
    }

    public void run() {
        for (int i = 0; i < 10000; i++) {
            demo.increment();
        }
    }
}

class ThreadB extends Thread {
    private SynchronizedMethodsDemo demo;

    public ThreadB(SynchronizedMethodsDemo demo) {
        this.demo = demo;
    }

    public void run() {
        for (int i = 0; i < 10000; i++) {
            demo.increment();
        }
    }
}

public class SynchronizeMethodsDemo {
    public static void main(String[] args) throws InterruptedException {
        SynchronizedMethodsDemo demo = new SynchronizedMethodsDemo();

        ThreadA threadA = new ThreadA(demo);
        ThreadB threadB = new ThreadB(demo);

        threadA.start();
        threadB.start();

        threadA.join();
        threadB.join();

        System.out.println("Count: " + demo.getCount());
    }
}
