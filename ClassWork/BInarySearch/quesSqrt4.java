// finding square root of element

package BInarySearch;

public class quesSqrt4 {
    public static long sqrt(int n) {
       long low = 1;
       long high = n;
       long ans = -1;

        while (low <= high) {
            long mid = (low + high)/2;
            if((long) (mid * mid) <= n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        int n = 5;
        System.out.println(sqrt(n));   
    }
}
