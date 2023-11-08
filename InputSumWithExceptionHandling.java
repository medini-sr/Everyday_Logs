/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
class Input_Exception extends Exception {
    public Input_Exception(String message) {
        super(message);
    }
}

public class InputSumWithExceptionHandling {
    public static void main(String[] args) {
        int sum = 0;
        boolean continueInput = true;
        
        while (continueInput) {
            try {
                int input = getUserInput();
                if (input == -1) {
                    continueInput = false;
                } else {
                    sum += input;
                }
            } catch (Input_Exception e) {
                System.out.println("Invalid input: " + e.getMessage());
            }
        }
        
        System.out.println("Sum of valid inputs: " + sum);
    }

    public static int getUserInput() throws Input_Exception {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Enter an integer or -1 to calculate sum: ");
        String inputStr = sc.next();
        
        try {
            int input = Integer.parseInt(inputStr);
            if (input == -1) {
                return input;
            } else {
                throw new Input_Exception("Floating-point numbers are not allowed.");
            }
        } catch (NumberFormatException e) {
            throw new Input_Exception("Invalid input. Please enter an integer or -1.");
        }
    }
}
