/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
//Write a program to enter student’s Name, Roll Number and Marks in three
//subjects and find the percentage, grade and handle NumberFormatException.
import java.util.*;
public class Studentdet {
    public static void main(String [] args)
    {
        Scanner sc= new Scanner(System.in);
        try{
        String s = sc.nextLine();
        int roll= sc.nextInt();
        int m1= Integer.parseInt(sc.next());
        int m2= Integer.parseInt(sc.next());
        int m3= Integer.parseInt(sc.next());
        int perc=((m1+m2+m3)/300)*100;
         
    }
        catch(NumberFormatException e)
        {
            System.out.println("NumberFormatException"+e.getMessage());
        }
}
}
