package Codechef;

import java.util.Scanner;

public class manCode {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            System.out.println((n+1)/2 + " " + (n+2)/3);
        }
        sc.close();   
    }
}
