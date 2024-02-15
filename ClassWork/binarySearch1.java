package ClassWork;

import java.util.Scanner;

public class binarySearch1 {
    public static int binSearch(int[] a, int l, int target) {
        int low = 0;
        int high = l-1;
        while (low <= high) {
            int mid = (low + high)/2;
            if(a[mid] == target)    return mid;
            else if(a[mid] < target)    low = mid + 1;
            else    high = mid -1 ;

        }
        return -1;
    }
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n];
    for(int i=0; i<=n-1; i++)   a[i] = sc.nextInt();

    int value = 12;
    int ans = binSearch(a, n, value);
    System.out.println(ans);
    sc.close();   
    }
}
