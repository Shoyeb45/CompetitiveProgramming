// Searching lower bound insertion point of given number

package ClassWork;
import java.util.*;
public class quesBinary4 {
    public static int lowerBound(int[] a, int x) {
        int lower = 0;
        int upper = a.length - 1;
        int LB = a.length;
        while (lower <= upper) {
            int mid = (lower + upper)/2;
            if(a[mid] < x) {
                lower = mid + 1;
            } else{
                LB = mid;
                upper = mid - 1;
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

        System.out.println(lowerBound(arr, x));
        sc.close();
    }
}
