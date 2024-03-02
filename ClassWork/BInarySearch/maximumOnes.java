package BInarySearch;

import java.util.*;

public class maximumOnes {
    public static int index (int[][] a, int i, int n) {
        int lower = 0, upper = n - 1 ;
        while (lower <= upper) {
            int mid = (lower + upper) / 2;
            if(mid != 0 &&  a[i][mid] == 1 && a[i][mid-1] == 0) {   
                return mid;
            }
            else if(mid == 0 && a[i][mid] == 1){
                return 0;
            }
            else if (a[i][mid] == 1) {
                upper = mid - 1;
            } 
            else if(a[i][mid] == 0) {
                lower  = mid + 1;
            }
        }
        return Integer.MAX_VALUE;
    }
    public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);   
    int m = sc.nextInt();
    int n = sc.nextInt();
        int[][] a = new int[m][n];

    for(int i=0; i<=m-1; i++)
        for(int j=0; j<=n-1; j++) a[i][j] = sc.nextInt();  

        int row = 0;
        int ind = -1;
        int minIndex = Integer.MAX_VALUE;
    for(int i=0; i<=m-1; i++) {
        ind = index(a, i, n);
        // System.out.println(ind);
        
        if(ind < minIndex ) {
        minIndex = ind;
        row = i + 1;
    }
    }
    // System.out.println(minIndex);
    System.out.println(row);
        
   
    sc.close();
    }
}
