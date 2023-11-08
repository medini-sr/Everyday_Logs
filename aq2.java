/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.Scanner;

class Student {
    private int regNumber;
    private String firstName;
    private String lastName;
    private String degree;

    public Student(int regNumber, String firstName, String lastName, String degree) {
        this.regNumber = regNumber;
        this.firstName = firstName;
        this.lastName = lastName;
        this.degree = degree;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    @Override
    public String toString() {
        return "Registration Number: " + regNumber + "\n" +
               "First Name: " + firstName + "\n" +
               "Last Name: " + lastName + "\n" +
               "Degree: " + degree + "\n";
    }
}

public class aq2 {
    public static void main(String[] args) {
        // Create an array of Student objects
        Student[] students = new Student[10];
        students[0] = new Student(1, "John", "Doe", "Computer Science");
        students[1] = new Student(2, "Alice", "Smith", "Mathematics");
        students[2] = new Student(3, "Bob", "Johnson", "Physics");
        students[3] = new Student(4, "Eva", "Brown", "Chemistry");
        students[4] = new Student(5, "Mike", "Wilson", "Engineering");
        students[5] = new Student(6, "Linda", "Davis", "Biology");
        students[6] = new Student(7, "James", "Lee", "History");
        students[7] = new Student(8, "Sarah", "Clark", "Psychology");
        students[8] = new Student(9, "David", "Hall", "Geology");
        students[9] = new Student(10, "Mary", "Miller", "English");

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the First Name or Last Name of the student to search: ");
        String searchName = scanner.nextLine();

        boolean found = false;

        for (Student student : students) {
            if (student.getFirstName().equalsIgnoreCase(searchName) ||
                student.getLastName().equalsIgnoreCase(searchName)) {
                System.out.println("Student Found:\n" + student);
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("Student not found.");
        }

        scanner.close();
    }
}
