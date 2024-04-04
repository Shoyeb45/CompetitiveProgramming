// package Codechef;

import java.util.Scanner;

public class smallestWholeNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            if(n < k)   System.out.println(n);
            else if (n == k)    System.out.println(0);
            else {
                
            }
        }
        sc.close();
    }
}
