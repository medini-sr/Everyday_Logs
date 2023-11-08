/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 *///Write a program for validating matrix*/
import java.util.Scanner;

class MatrixValidationException extends Exception {
    public MatrixValidationException(String message) {
        super(message);
    }
}

public class MatrixValidationWithExceptionHandling {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
        
            int rows = sc.nextInt();
           
            int columns = sc.nextInt(); 

            if (rows != columns) {
                throw new MatrixValidationException("The matrix is not square.");
            }

            int[][] matrix = new int[rows][columns];
            
            System.out.println("Enter the elements of the matrix:");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    matrix[i][j] = sc.nextInt();
                }
            }

            System.out.println("Matrix is valid and square.");
        } catch (MatrixValidationException e) {
            System.out.println("Matrix Validation Error: " + e.getMessage());
        } catch (Exception ex) {
            System.out.println("An unexpected error occurred: " + ex.getMessage());
        } 
        
    }
}
