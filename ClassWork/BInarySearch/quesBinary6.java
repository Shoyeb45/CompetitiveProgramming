package BInarySearch;
// Finding the frequency of given element.

import java.util.Scanner;

public class quesBinary6 {
    // Function for finding upper bound
    public static int upperBound(int[] a, int x) {
        int low = 0;
        int high = a.length - 1;
        int UB = a.length;
        while (low <= high) {
            int mid = (low + high)/2;
            if(a[mid] > x) {
                high = mid - 1;
            } else {
                UB = mid + 1;
                low = mid + 1;
            }
        }
        return UB;
    }
    // Function for finding lower bound
    public static int lowerBound(int[] a, int x) {
        int low = 0;
        int high = a.length - 1;
        int LB = a.length;
        while (low <= high) {
            int mid = (low + high)/2;
            if(a[mid] < x) {
                low = mid + 1;
            } else {
                LB = mid;
                high = mid - 1;
            }
        }
        return LB;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i=0; i<=n-1; i++) arr[i] = sc.nextInt();
        int x = sc.nextInt();

        System.out.println(freq(arr, x));
        sc.close();
    }  
    public static int freq (int[] a, int x) {
        return upperBound(a, x) - lowerBound(a, x);
    }  
}
