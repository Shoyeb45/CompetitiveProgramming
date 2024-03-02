package BInarySearch;
// Searching upper bound insertion point of given number

import java.util.Scanner;

public class quesBinary5 {
    public static int upperBound(int[] a, int x) {
        int lower = 0;
        int upper = a.length - 1;
        int UB = 0;
        while (lower <= upper) {
            int mid = (lower + upper)/2;
            if(a[mid] > x) {
                upper = mid - 1;
            } else {
                UB = mid+1;
                lower = mid + 1;    
            }
        }
        return UB;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i=0; i<=n-1; i++) arr[i] = sc.nextInt();
        int x = sc.nextInt();

        System.out.println(upperBound(arr, x));
        sc.close();
    }
}
