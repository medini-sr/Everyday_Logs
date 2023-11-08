import java.util.Scanner;

public class menu {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter a string:");
        String inputString = scanner.nextLine();

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Check whether it's a palindrome");
            System.out.println("2. Write in alphabetical order");
            System.out.println("3. Reverse the string");
            System.out.println("4. Concatenate original and reversed string");
            System.out.println("5. Exit");
            System.out.print("Enter your choice (1/2/3/4/5): ");

            int choice = scanner.nextInt();
            scanner.nextLine(); 
            switch (choice) {
                case 1:
                    if (isPalindrome(inputString)) {
                        System.out.println("The string is a palindrome.");
                    } else {
                        System.out.println("The string is not a palindrome.");
                    }
                    break;
                case 2:
                    String sortedString = sortStringAlphabetically(inputString);
                    System.out.println("Alphabetically Sorted String: " + sortedString);
                    break;
                case 3:
                    String reversedString = reverseString(inputString);
                    System.out.println("Reversed String: " + reversedString);
                    break;
                case 4:
                    String concatenatedString = inputString + reverseString(inputString);
                    System.out.println("Concatenated String: " + concatenatedString);
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

    public static boolean isPalindrome(String str) {
        str = str.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
        int left = 0;
        int right = str.length() - 1;
        while (left < right) {
            if (str.charAt(left) != str.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    public static String sortStringAlphabetically(String str) {
        char[] charArray = str.toCharArray();
        java.util.Arrays.sort(charArray);
        return new String(charArray);
    }

    public static String reverseString(String str) {
        return new StringBuilder(str).reverse().toString();
    }
}
