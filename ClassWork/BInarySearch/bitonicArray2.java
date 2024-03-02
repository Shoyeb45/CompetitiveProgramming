// Checking a target number exist or not in an bitonic array, if exist return index else -1

package BInarySearch;

import java.util.Scanner;

public class bitonicArray2 {
    // Function for finding bitonic point
    public static int bitonicPoint(int[] a) {
        int low = 1;
        int high = a.length - 2;
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if(a[mid] > a[mid+1] && a[mid] > a[mid-1]) {
                ans = mid;
                break;
            } else if (a[mid] > a[mid+1] && a[mid] < a[mid-1]) {
                low = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    // Function for finding target element in first half
    public static int increase(int[] a, int target, int bp) {
        int lower = 0;
        int upper = bp;
        int ind = -1;
        while (lower <= upper) {
            int mid = (lower + upper) / 2;
            if(a[mid] == target) {
                ind = mid;
                break;
            } else if (a[mid] > target) {
                upper = mid - 1;
            } else {
                lower = mid + 1;
            }
        }    
        return ind;
    }
    // Function for finding target element in second half
    public static int decrease(int[] a, int target, int bp) {
        int lower = bp+1;
        int upper = a.length - 1;
        int ind = -1;
        while (lower <= upper) {
            int mid = (lower + upper) / 2;
            if(a[mid] == target) {
                ind = mid;
                break;
            } else if (a[mid] > target) {
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }    
        return ind;
    }
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int[] arr = new int[n];
    
    for (int i=0; i<n; i++) {
        arr[i] = sc.nextInt();
    }
    int x = sc.nextInt(); //target element

    int bp = bitonicPoint(arr);
    int inc = increase(arr, x, bp);
    int dec = decrease(arr, x, bp);
    if(inc + dec < 0) {
        System.out.println(x+" does not exist in array.");
    } else if (inc > 0 && dec < 0) {
        System.out.println("Index of "+x+" is "+inc);
    }else {
        System.out.println("Index of "+x+" is "+dec);
    }
    sc.close();    
    }
}
