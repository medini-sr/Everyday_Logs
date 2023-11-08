/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;

public class count1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter a string (press Enter to finish):");
        StringBuilder inputText = new StringBuilder();
        while (true) {
            String line = scanner.nextLine();
            if (line.isEmpty()) {
                break;
            }
            inputText.append(line).append("\n");
        }
        scanner.close();

        
        int charCount = inputText.length();
        int wordCount = countWords(inputText.toString());
        int lineCount = inputText.toString().split("\n").length;
        int vowelCount = countVowels(inputText.toString());

        System.out.println("Character Count: " + charCount);
        System.out.println("Word Count: " + wordCount);
        System.out.println("Line Count: " + lineCount);
        System.out.println("Vowel Count: " + vowelCount);
    }

    public static int countWords(String text) {
        String[] words = text.split("\\s+");
        return words.length;
    }


    public static int countVowels(String text) {
        int vowelCount = 0;
        text = text.toLowerCase(); 
        for (int i = 0; i < text.length(); i++) {
            char ch = text.charAt(i);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;
            }
        }
        return vowelCount;
    }
}

