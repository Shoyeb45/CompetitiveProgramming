// Find index of minimum element in rotated sorted array.
package ClassWork;

import java.util.*;

public class rotatedSortArray {
    public static int mimInRotated(int[] a) {
        int lower = 0;
        int upper = a.length - 1;
        int ans = 0;
        while (lower <= upper) {
            int mid = (lower + upper)/2;
            if(a[mid] > a[mid+1]) {   
                ans = mid;
                break;
            } else if (a[mid] < a[0]) {  // in left half of array the elements will be less than the minimum element of first half.
                upper = mid - 1;
            } else {              // in right half of array the elements will be greater than the maximum element of second half.
                lower = mid + 1;
            }
        }
        return ans+1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];

        for(int i=0; i<n; i++)  arr[i] = sc.nextInt();

        int min = mimInRotated(arr);
        System.out.println("Index of minimum element in rotated array is "+min+".");
        sc.close();
    }
}
