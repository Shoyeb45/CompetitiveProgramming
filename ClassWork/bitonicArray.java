// Bitonic array is array where first value of element increase and then decrease or vice-versa, find the index of target element.

package ClassWork;

import java.util.Scanner;

public class bitonicArray {
    public static int index(int arr[], int target) {
        int lower1 = 0, upper1 = arr.length-1;
        int lower2 = 0, upper2 = arr.length-1;
        int ans = -1;
        while (lower1 <= upper1 && lower2 <= upper2) {
            int mid1 = (lower1 + upper1)/2;
            int mid2 = (lower2 + upper2)/2;

            if(arr[mid1] == target) ans = mid1;
            else if(arr[mid2] == target)    ans = mid2;
            else if(arr[mid1] > target || arr[mid2] > target) {
                upper1 = mid1 - 1;
                upper2 = mid2 - 1;
            } else if(arr[mid1] > target || arr[mid2] < target){
                upper1 = mid1 - 1;
                lower2 = mid2 + 1;
            } else if(arr[mid1] < target || arr[mid2] > target) {
                lower1 = mid1 + 1;
                upper2 = mid2 - 1;
            } else {
                lower1 = mid1 + 1;
                lower2 = mid2 + 1;
            }
        }
        return ans;
    }
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int[] arr = new int[n];
    
    for(int i=0; i<=n-1; i++)   arr[i] = sc.nextInt();
    int target = sc.nextInt();

    System.out.println(index(arr, target));
    }
}
