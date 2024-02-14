package Codechef;

import java.util.Scanner;

public class motivation {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
     
    for(int p=1; p<=t; p++) {
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] size = new int[n];
        int[] rating = new int[n];

        for(int i=0; i<=n-1; i++) {
            size[i] = sc.nextInt();
            rating[i] = sc.nextInt();
        }
        
        for(int i=0; i<=n-1; i++) {
            if(size[i] > x)   size[i] = -1;
        }

        int maxRating = 0;
        for(int i=0; i<=n-1; i++) {
            if(size[i] != -1 && maxRating <= rating[i])   maxRating = rating[i];
        }
        System.out.println(maxRating);
    } 
    sc.close();
    }
}
