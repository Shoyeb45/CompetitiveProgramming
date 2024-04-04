// package Codechef;

import java.util.Scanner;

public class minNoOfPizza {
    public static int GCD(int a, int b){
        if(b == 0)
        return a;

        return GCD(b, a % b);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for(int i = 1; i<=T ; i++){
            int N = sc.nextInt();
            int K = sc.nextInt();

            // for(int p = 1; ;p++){
            //     if( (K * p) % N == 0){
            //         System.out.println(p);
            //         break;
            //     }
            // }

            // int lcm = (N * K)/ GCD(N, K);
            // System.out.println(lcm/K);

            System.out.println(N / GCD(N, K));
        }

        sc.close();
    }
    
}
