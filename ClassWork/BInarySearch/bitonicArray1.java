// Bitonic array is array where first value of element increase and then decrease or vice-versa, find the index of largest element.

package BInarySearch;

import java.util.Scanner;

public class bitonicArray1 {
    public static int BitonicPoint(int[] a) {
        int lower = 1;
        int upper = a.length - 2;

        int ans = 0;
        while (lower <= upper) {
            int mid = (lower + upper) / 2;
            if(a[mid] > a[mid + 1] && a[mid] > a[mid - 1]) {
                ans = mid;
                break;
            } else if (a[mid] < a[mid+1] && a[mid] > a[mid-1]) {
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }
        return ans;
    }
    
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];
        
        for (int i=0; i<n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println("Index of bitonic array is "+BitonicPoint(arr) + "\nAnd Element is " + arr[BitonicPoint(arr)]);
        sc.close();
    
    }
}

