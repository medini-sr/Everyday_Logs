class Matrix {
    private int[][] matrix;
    private int rows;
    private int cols;

    public Matrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        this.matrix = new int[rows][cols];
        // Initialize the matrix with some values (you can modify this part as needed).
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = i * cols + j + 1;
            }
        }
    }

    public int getRows() {
        return rows;
    }

    public int getCols() {
        return cols;
    }

    public int getElement(int i, int j) {
        return matrix[i][j];
    }
}

class DisplayMatrixThread extends Thread {
    private Matrix matrix;

    public DisplayMatrixThread(Matrix matrix) {
        this.matrix = matrix;
    }

    public void run() {
        System.out.println("Matrix:");
        for (int i = 0; i < matrix.getRows(); i++) {
            for (int j = 0; j < matrix.getCols(); j++) {
                System.out.print(matrix.getElement(i, j) + " ");
            }
            System.out.println();
        }
    }
}

class TransposeMatrixThread extends Thread {
    private Matrix matrix;

    public TransposeMatrixThread(Matrix matrix) {
        this.matrix = matrix;
    }

    public void run() {
        System.out.println("Transpose of the Matrix:");
        for (int j = 0; j < matrix.getCols(); j++) {
            for (int i = 0; i < matrix.getRows(); i++) {
                System.out.print(matrix.getElement(i, j) + " ");
            }
            System.out.println();
        }
    }
}

class MaxValueThread extends Thread {
    private Matrix matrix;

    public MaxValueThread(Matrix matrix) {
        this.matrix = matrix;
    }

    public void run() {
        int max = matrix.getElement(0, 0);
        for (int i = 0; i < matrix.getRows(); i++) {
            for (int j = 0; j < matrix.getCols(); j++) {
                if (matrix.getElement(i, j) > max) {
                    max = matrix.getElement(i, j);
                }
            }
        }
        System.out.println("Maximum value in the Matrix: " + max);
    }
}

class PrincipalDiagonalThread extends Thread {
    private Matrix matrix;

    public PrincipalDiagonalThread(Matrix matrix) {
        this.matrix = matrix;
    }

    public void run() {
        System.out.println("Principal Diagonal Elements:");
        for (int i = 0; i < matrix.getRows() && i < matrix.getCols(); i++) {
            System.out.print(matrix.getElement(i, i) + " ");
        }
        System.out.println();
    }
}

class NonDiagonalThread extends Thread {
    private Matrix matrix;

    public NonDiagonalThread(Matrix matrix) {
        this.matrix = matrix;
    }

    public void run() {
        System.out.println("Non-Diagonal Elements:");
        for (int i = 0; i < matrix.getRows(); i++) {
            for (int j = 0; j < matrix.getCols(); j++) {
                if (i != j) {
                    System.out.print(matrix.getElement(i, j) + " ");
                }
            }
        }
        System.out.println();
    }
}

public class MatrixOperations {
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
    }
}
