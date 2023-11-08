/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author student
 *///Create a user defined exception class which displays error message.
class Userdrfexception extends Exception{
    Userdrfexception(String s)
    {
        super(s);
    }
}
public class Userdef {
    public static void main(String [] args)
    {
        try{
            throw new Userdrfexception("im blue da ba dee da ba daaaaaaa");
        }
        catch(Userdrfexception e)
        {
            System.out.println("im not blue anymore:<"+e.getMessage());
        }
    }
}
