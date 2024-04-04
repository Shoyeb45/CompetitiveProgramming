// package Codechef;

import java.util.Scanner;

public class theTwoDishes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int p=1; p<=t; p++) {
            int n = sc.nextInt();
            int s = sc.nextInt();

            if ( s <= n)  System.out.println(s);
            else {
                System.out.println(2*n - s);
            }
        }
        sc.close();
    }    
}
