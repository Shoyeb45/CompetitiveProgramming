// package Codechef;

import java.util.Scanner;

public class antiAdjacentSwaps {
    public static boolean isSorted(int[] a, int init ,int len) {
        boolean o = true;

        for(int i=init; i<len-1; i++) {
            if(a[i] <= a[i+1])
                o = true;
            else {
                o = false;
                break;
            }
        }
        return o;
    }
    public static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for(int i=0; i<n; i++)  a[i] = sc.nextInt();
            
            if(isSorted(a, 0, n)) System.out.println("YES");
            else {
                for(int i=0; i<=n-3; i++) {
                    for(int j=i+2; j<=n-1; j++) {
                        if(a[i] >= a[j])
                            swap(a, i, j);
                    }
                }
                if(isSorted(a, 0, n)) System.out.println("YES");
                else System.out.println("NO");
            }
        }
        sc.close();
    }
}
