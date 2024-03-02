package Recursion;

import java.util.Scanner;

public class q1 {
    public static int calcFacto(int n){
        //Base case
     if (n ==1 || n ==0){
        return 1;
     }
        int facto = calcFacto(n-1);  //Recursive statement
        int fact_n = n * facto ;
        return fact_n;  
       
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n= sc.nextInt();
        sc.close();
      System.out.println( calcFacto(n));
    }

}
