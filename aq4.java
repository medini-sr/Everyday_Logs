/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;

public class aq4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        
        System.out.print("Enter a telephone number in the form (555) 555-5555: ");
        String phoneNumber = scanner.nextLine();

        String areaCode = extractAreaCode(phoneNumber);
        String firstThreeDigits = extractFirstThreeDigits(phoneNumber);
        String lastFourDigits = extractLastFourDigits(phoneNumber);

       
        System.out.println("\nArea Code: " + areaCode);
        System.out.println("First Three Digits: " + firstThreeDigits);
        System.out.println("Last Four Digits: " + lastFourDigits);

        scanner.close();
    }

  
    public static String extractAreaCode(String phoneNumber) {
      
        int startIndex = phoneNumber.indexOf('(') + 1;
        int endIndex = phoneNumber.indexOf(')');
        return phoneNumber.substring(startIndex, endIndex);
    }

  
    public static String extractFirstThreeDigits(String phoneNumber) {
      
        int startIndex = phoneNumber.indexOf(')') + 2;
        int endIndex = phoneNumber.indexOf('-');
        return phoneNumber.substring(startIndex, endIndex);
    }

    public static String extractLastFourDigits(String phoneNumber) {
        
        int startIndex = phoneNumber.lastIndexOf('-') + 1;
        return phoneNumber.substring(startIndex);
    }
}
