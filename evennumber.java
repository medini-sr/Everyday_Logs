/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 *///Write a program to raise EvenNumberException if the number is even
import java.util.*;
class Evenex extends Exception{
    Evenex(String s){
        super(s);
    
}
}
public class evennumber {
    public static void main(String agrs[]){
        Scanner sc=new Scanner(System.in);
        try{
            int n= sc.nextInt();
            if(n%2==0)
            {
                throw new Evenex("EVENNUMBEREXCEPTION :the number entered is an even number ");
                
            }
            else 
                System.out.println("the entered number is "+n);
        }catch(Evenex e)
        {
            System.out.println(":"+e.getMessage());
        }
    }
}
