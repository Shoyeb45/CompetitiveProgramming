package Recursion;

import java.util.Scanner;

public class q2 {
    public static void print(int n){
        if(n == 0)
        return;
        print(n-1);
        System.out.println(n);
        return;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        print(n);
        sc.close();
    }

}
