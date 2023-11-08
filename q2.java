/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;

public class q2{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the word you want to replace:");
        String wordToReplace = scanner.nextLine();

        System.out.println("Enter the text:");
        String inputText = scanner.nextLine();

        scanner.close();

        String resultText = replaceWordWithRepeatingCharacters(inputText, wordToReplace);

        System.out.println("Original Text:");
        System.out.println(inputText);

        System.out.println("Modified Text:");
        System.out.println(resultText);
    }

    public static String replaceWordWithRepeatingCharacters(String text, String word) {
        StringBuilder result = new StringBuilder();
        int wordLength = word.length();

        for (int i = 0; i < text.length(); i++) {
            boolean foundWord = false;
            int j;
            
            for (j = 0; j < wordLength && i + j < text.length(); j++) {
                if (text.charAt(i + j) != word.charAt(j)) {
                    break;
                }
            }
            
            if (j == wordLength) {
             
                for (int k = 0; k < wordLength; k++) {
                    result.append(word.charAt(k));
                }
                foundWord = true;
                i += wordLength - 1;
            }
            
            if (!foundWord) {
               
                result.append(text.charAt(i));
            }
        }

        return result.toString();
    }
}

