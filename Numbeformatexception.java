/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.*;
public class Numbeformatexception {
    public static void main(String args[])
    {
        int n;
        Scanner sc= new Scanner(System.in);
        
        try{
            n = Integer.parseInt(sc.next());
            
        }
        catch(NumberFormatException e){
            System.out.println("Number format exception occured");
        }
       
       
    }
}
