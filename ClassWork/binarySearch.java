package ClassWork;
import java.util.*;

public class binarySearch {
    public static int index(int[] arr, int target) {    
        int upper = arr.length - 1;
        int lower = 0;

        while (lower <= upper) {
            int mid = (upper + lower)/ 2;

            if(arr[mid] == target)    return mid;
            else if(arr[mid] < target)   lower = mid +1;
            else    upper = mid - 1;
        }

        return -1;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int target = sc.nextInt();
        int[] arr = new int[n];

        for(int i=0; i<n; i++)  arr[i] = sc.nextInt();

        System.out.println(index(arr, target));
    }   
}
