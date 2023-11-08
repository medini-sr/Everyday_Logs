/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.*;
class Negativeroot extends Exception{
    Negativeroot(String s){
    super(s);
}
}
public class negativroot {
    public static void main(String args[]) throws Negativeroot
    {
        Scanner sc = new Scanner(System.in);
        try{
            int n= sc.nextInt();
            
            if(n<0)
                throw new Negativeroot("the entered number is negative ");
            else 
            {
                int square=n*n;
                System.out.println("the square of the entered number is"+square);
            }           
        }catch(Negativeroot e)
        {
            System.out.println(":"+e.getMessage());
        }
         
    }
}
