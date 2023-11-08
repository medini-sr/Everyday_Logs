/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.*;
class Marksoutofboundsexception extends Exception{
    Marksoutofboundsexception(String s){
        super(s);
    }
}

public class Student {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        try{
            String s = sc.nextLine();
            int n= sc.nextInt();
            if(n>100)
            {
                throw new Marksoutofboundsexception("MarksOutOfBoundsException : the number entered is greater than 100");
            }
            else
                System.out.println("the number entered is"+n);
        }catch(Marksoutofboundsexception e)
        {
            System.out.println(":"+e.getMessage());
        }
    }
}
