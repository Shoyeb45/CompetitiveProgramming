package ClassWork.Recursion;

import java.util.Scanner;

public class q3 {
    public static void Reverse(String name , int n ,String  reve ) {
        if(n == 0 ){
            reve = reve +name.charAt(n);
            System.out.println(reve);
            return;
        }

        Reverse(name, n-1, reve+name.charAt(n));
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
               String name =sc.nextLine();
                 
                Reverse(name,  name.length()-1, "");
                  sc.close();    

          
    }
    
}
