// package Codechef;

import java.util.Scanner;

public class hoopJump {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            System.out.println(n/2 + 1);       
        }
        sc.close();
    } 
}
