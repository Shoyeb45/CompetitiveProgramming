// Find the index of target element if exist else output some msg that contains unavailability of target element

package ClassWork;

import java.util.Scanner;

public class rotatedSortedArray2 {
    public static int minInRotated(int[] a) {
        int lower = 0;
        int upper = a.length - 1;
        int ans = a.length ;
        while (lower <= upper) {
            int mid = (lower + upper)/2;
            if(mid < a.length-1 && a[mid] > a[mid+1]) {   
                ans = mid+1;
                break;
            } else if (a[mid] < a[0]) {  
                upper = mid - 1;
            } else {              
                lower = mid + 1;
            }
        }
        return ans;
    }

    public static int binarySearch(int[] a, int x, int start, int end) {
        int lower = start;
        int upper = end;
        int ind = -1;
        while (lower <= upper) {
            int mid = (lower + upper)/2;
            if(a[mid] == x) {
                ind = mid;
                break;
            } else if(a[mid] > x) {
                upper = mid - 1;
            } else {
                lower = mid + 1;
            }
        }
        return ind;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        
        for(int i=0; i<n; i++)  arr[i] = sc.nextInt();
        int x = sc.nextInt();

        int min = minInRotated(arr);
        int index = 0;
        if(arr[0] > x) {
            index = binarySearch(arr, x, min, arr.length - 1);
        } else {
            index = binarySearch(arr, x, 0, min-1);
        }

        if(index < 0){
            System.out.println("Target element does not exist.");
        } else {
            System.out.println("Index of "+x+" is "+index);
        }
        sc.close();
    }
}
