package Codechef;

import java.util.Scanner;

public class distinctPairSum {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            System.out.println((long)((2*(r-l)+1)));
        }

        sc.close();
    }
}