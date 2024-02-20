// Checking a target number exist or not in an bitonic array

package ClassWork;

import java.util.Scanner;

public class bitonicArray2 {
    public static boolean increase(int[] a, int k) {
        int lower = 0;
        int upper = k - 1;
        
    }
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int[] arr = new int[n];
    
    for (int i=0; i<n; i++) {
        arr[i] = sc.nextInt();
    }

    System.out.println();
    sc.close();    
    }
}
