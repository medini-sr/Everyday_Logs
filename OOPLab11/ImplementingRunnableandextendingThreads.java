
import java.util.*;
class Mythread extends Thread{
    public void run()
    {
        System.out.println("Extended Thread class successfully");
    }
}
class MyRunnable implements Runnable{
    public void run()
    {
        System.out.println("Implemnting Runnable");
    }
}
public class Lab_11oop {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;
        String c;
        do{
            choice=sc.nextInt();
            switch(choice)
            {
                case 1:Mythread ob1= new Mythread();
                break;
                case 2: MyRunnable ob2 = new MyRunnable();
                break;
                default:
                    System.out.println("Invalid ");
                    break;
            }
            System.out.println("do you wanna continue? y/n");
            c =sc.nextLine();     
        }while("y".equals(c) || "Y".equals(c));
    }
}
