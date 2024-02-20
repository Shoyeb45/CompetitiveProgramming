// Bitonic array is array where first value of element increase and then decrease or vice-versa, find the index of largest element.

package ClassWork;

import java.util.Scanner;

public class bitonicArray {
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
    // public static int BitonicPoint(int[] a) {
    //     int lower = 0;
    //     int upper = a.length - 1;
    
    //     while (lower <= upper) {
    //         int mid = lower + (upper - lower) / 2;
    
    //         if (mid > 0 && mid < a.length - 1) {
    //             if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1]) {
    //                 return mid;
    //             } else if (a[mid - 1] > a[mid]) {
    //                 upper = mid - 1;
    //             } else {
    //                 lower = mid + 1;
    //             }
    //         } else {
    //             return -1; // Array is not bitonic
    //         }
    //     }
    //     return -1; // Should never reach here
    // }
    
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int[] arr = new int[n];
    
    for (int i=0; i<n; i++) {
        arr[i] = sc.nextInt();
    }

    System.out.println(BitonicPoint(arr));
    sc.close();
    
    }
}

