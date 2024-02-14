package Codechef;

import java.util.Scanner;

public class twoDishes {
    public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
     
    for(int p=1; p<=t; p++) {
        int n = sc.nextInt();
        int fruits = sc.nextInt();
        int vegetables = sc.nextInt();
        int fish = sc.nextInt();

        if(vegetables >= n) {
            if(fish + fruits >= n)  System.out.println("YES");
            else    System.out.println("NO");
        } else  System.out.println("NO");
        } 

    sc.close();
    }
}
