class MatrixOperations {
    public static void main(String[] args) {
        Matrix matrix = new Matrix(3, 3);

        DisplayMatrixThread t1 = new DisplayMatrixThread(matrix);
        TransposeMatrixThread t2 = new TransposeMatrixThread(matrix);
        MaxValueThread t3 = new MaxValueThread(matrix);
        PrincipalDiagonalThread t4 = new PrincipalDiagonalThread(matrix);
        NonDiagonalThread t5 = new NonDiagonalThread(matrix);

        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();

        // Check if the threads are alive and wait for them to finish.
        while (t1.isAlive() || t2.isAlive() || t3.isAlive() || t4.isAlive() || t5.isAlive()) {
            try {
                t1.join();
                t2.join();
                t3.join();
                t4.join();
                t5.join();
            } catch (InterruptedException e) {
                System.err.println("Thread interrupted.");
            }
        }

        System.out.println("All threads have finished their tasks.");
    }
}
