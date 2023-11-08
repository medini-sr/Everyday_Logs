/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;

public class menu2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the first string:");
        String string1 = scanner.nextLine();

        System.out.println("Enter the second string:");
        String string2 = scanner.nextLine();

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Compare two strings");
            System.out.println("2. Convert uppercase to lowercase and vice versa");
            System.out.println("3. Check if one string is a substring of the other");
            System.out.println("4. Replace substring with 'Hello'");
            System.out.println("5. Exit");
            System.out.print("Enter your choice (1/2/3/4/5): ");

            int choice = scanner.nextInt();
            scanner.nextLine();
            switch (choice) {
                case 1:
                    int comparisonResult = string1.compareTo(string2);
                    if (comparisonResult == 0) {
                        System.out.println("The two strings are equal.");
                    } else if (comparisonResult < 0) {
                        System.out.println("String 1 is smaller than String 2.");
                    } else {
                        System.out.println("String 1 is greater than String 2.");
                    }
                    break;
                case 2:
                    System.out.println("Enter '1' to convert to uppercase to lowercase, or '2' for vice versa:");
                    int conversionChoice = scanner.nextInt();
                    scanner.nextLine(); 

                    if (conversionChoice == 1) {
                        string1 = string1.toLowerCase();
                        string2 = string2.toLowerCase();
                    } else if (conversionChoice == 2) {
                        string1 = string1.toUpperCase();
                        string2 = string2.toUpperCase();
                    } else {
                        System.out.println("Invalid choice.");
                    }
                    System.out.println("String 1: " + string1);
                    System.out.println("String 2: " + string2);
                    break;
                case 3:
                    if (string1.contains(string2)) {
                        System.out.println("String 2 is a substring of String 1.");
                    } else if (string2.contains(string1)) {
                        System.out.println("String 1 is a substring of String 2.");
                    } else {
                        System.out.println("Neither string is a substring of the other.");
                    }
                    break;
                case 4:
                    if (string1.contains(string2)) {
                        string1 = string1.replace(string2, "Hello");
                    } else if (string2.contains(string1)) {
                        string2 = string2.replace(string1, "Hello");
                    }
                    System.out.println("Modified String 1: " + string1);
                    System.out.println("Modified String 2: " + string2);
                    break;
                case 5:
                    System.out.println("Exiting the program.");
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        }
    }
}
