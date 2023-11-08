/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.*;
public class ArrayOverflowException {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int a[]= new int[n];
        int i;
        try{
            for( i=0;i<n;i++)
            {
                a[i]=sc.nextInt();
            }
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("the size of the array exceeds the capacity set for it"+ e.getMessage());
            
        }
    }
}
