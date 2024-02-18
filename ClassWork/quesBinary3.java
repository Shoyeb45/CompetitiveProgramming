// finding element in array such that a[i] = i

package ClassWork;

import java.util.Scanner;

public class quesBinary3 {
    public static int Search(int[] a, int l, int target) {
        int low = 0;
        int high = l-1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high)/2;
            if(a[mid] >= mid) {
                ans = mid;
                break;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n];
    for(int i=0; i<=n-1; i++)   a[i] = sc.nextInt();

    
    int ans = Search(a, n, 6);
    System.out.println(ans);
    sc.close();   
    }
}
