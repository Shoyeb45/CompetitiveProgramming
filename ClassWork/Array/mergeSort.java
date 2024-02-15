package ClassWork.Array;

import java.util.Scanner;

public class mergeSort {
    public static int[] merge(int[] a, int[] b, int n, int m) {
        int k=0;
        int[] c = new int[n+m];
        for(int i=0, j=0; i < n || j < m; ) {
            if(i == n) {
                c[k] = b[j];
                j++;
                k++;
            }
            else if (j == m) {
                c[k] = a[i];
                i++;
                k++;
            } else if (a[i] <= a[j]) {
                c[k] = a[i];
                i++;
                k++;
            } else {
                c[k] = b[j];
                j++;
                k++;
            }
        }
        return c;
    }    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[m];

        for(int i=0; i<=n-1; i++)
            a[i] = sc.nextInt();

        for(int i=0; i<=m-1; i++)
            b[i] = sc.nextInt();
      
        int[] c = merge(a, b, n, m);
        for(int i=0; i<c.length; i++)
        System.out.print(c[i]+" ");
        
        sc.close();


    }
    
}
