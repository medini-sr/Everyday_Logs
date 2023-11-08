/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;

public class aq5{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

      
        System.out.print("Enter a five-letter word: ");
        String inputWord = scanner.nextLine();

        if (inputWord.length() != 5) {
            System.out.println("Invalid input. Please enter a five-letter word.");
        } else {
            System.out.println("\nPossible Three-Letter Words:");
            generateThreeLetterWords(inputWord);
        }

        scanner.close();
    }


    public static void generateThreeLetterWords(String word) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (i != j && i != k && j != k) {
                       
                        String threeLetterWord = "" + word.charAt(i) + word.charAt(j) + word.charAt(k);
                        System.out.println(threeLetterWord);
                    }
                }
            }
        }
    }
}

