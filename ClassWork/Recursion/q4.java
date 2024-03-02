package Recursion;

import java.util.Scanner;

public class q4 {
    public static void Fibo(long a, long b, int n){
        if(n == 0)
        return;

        System.out.print(" "+(a+b));
        Fibo(b, a+b, n-1);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n:");
        int n = sc.nextInt();

        System.out.print("0 1");
        long a = 0, b = 1;
        Fibo(a, b, n);
        sc.close();
    }
}
