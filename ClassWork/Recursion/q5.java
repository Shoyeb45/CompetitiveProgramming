package Recursion;

import java.util.Scanner;

public class q5 {
        public static long modExpo(long b, long p, long m){
        if(p == 0)
        return 1;
        if(p == 1)
        return b % m;
        long temp = modExpo(b, p/2, m);

        if(p % 2 == 1){
            return (temp * temp * b) % m;
        }else{
            return (temp * temp ) % m;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long b = sc.nextLong();
        long p = sc.nextLong();
        long m = sc.nextLong();

        System.out.println(modExpo(b, p, m));
        sc.close();
    }
}
