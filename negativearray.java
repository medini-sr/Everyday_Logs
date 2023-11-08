/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 */
import java.util.*;
class Negativearraysize extends Exception{
    Negativearraysize(String s)
    {
        super(s);
    }
}
public class negativearray {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        try{
            int n=sc.nextInt();
            int[] a= new int[n];
            if(n<0)
            {
                throw new Negativearraysize ("the size entered is negative.An array cant have negative size");
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    a[i]=sc.nextInt();
                }
            }
        }catch(Negativearraysize e)
        {
            System.out.println(":"+e.getMessage());
        }
    }
}
