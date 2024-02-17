package ClassWork;

import java.util.*;

public class maximumOnes {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);   
    int m = sc.nextInt();
    int n = sc.nextInt();
        int[][] a = new int[m][n];
    for(int i=0; i<=m-1; i++)
        for(int j=0; j<=n-1; j++) a[i][j] = sc.nextInt();  

        int[] r = new int[m];
        int row = 0;
        int minIndex = 0 ;
    for(int i=0; i<=m-1; i++) {
        int mid = n/2;
        while(mid != 0 )
        if(a[i][mid] == 1) {
            mid = mid - 1;
        } else {
            if(a[i][mid+1] == 0 && mid+1 != n)    mid = mid +2;
            else {  
                r[i] = mid+1;
                break;
            }
        }
        if(minIndex >= r[i]) minIndex = r[i];
    }

    for(int i=0; i<=m-1; i++) {
        if(minIndex == r[i]) {
            System.out.println(i+1);
        }
    }
    sc.close();
    }
}
