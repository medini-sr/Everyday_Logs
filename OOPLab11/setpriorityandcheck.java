class PriorityThread extends Thread {
    public PriorityThread(String name) {
        super(name);
    }

    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println(getName() + " is running, iteration " + i);
            try {
                Thread.sleep(1000); // Simulate some work
            } catch (InterruptedException e) {
                System.out.println(getName() + " was interrupted.");
                return; // Terminate the thread when interrupted
            }
        }
        System.out.println(getName() + " has completed its task.");
    }
}

public class ThreadPriorityDemo {
    public static void main(String[] args) {
        PriorityThread t1 = new PriorityThread("Thread 1");
        PriorityThread t2 = new PriorityThread("Thread 2");

        // Set thread priorities
        t1.setPriority(Thread.MIN_PRIORITY); // Min priority
        t2.setPriority(Thread.MAX_PRIORITY); // Max priority

        t1.start();
        t2.start();

        // Interrupt thread t1 after 3 seconds
        try {
            Thread.sleep(3000);
            t1.interrupt();
        } catch (InterruptedException e) {
            System.out.println("Main thread was interrupted.");
        }

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            System.out.println("Main thread was interrupted while waiting for threads to finish.");
        }

        System.out.println("Main thread has completed.");
    }
}
