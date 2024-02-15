package ClassWork.Array;

import java.util.Scanner;

public class mergeSort {
    public static int[] merge(int[] a, int[] b) {
        int[] c = new int[a.length + b.length];
        int i = 0, j = 0, k = 0;
        for(i = 0, j = 0 ; j < b.length || i < a.length; ) {
            if(i == a.length) {
                c[k] = b[j];
                j++;
                k++;
            } else if (j == b.length) {
                c[k] = a[i];
                i++;
                k++;
            } else if (a[i] <= b[j]) {
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

    public static int[] sort(int[] a) {
        if(a.length == 1) return a;

        int len = a.length;
        int[] tempA = new int[(len+1)/2];
        int[] tempB = new int[len - (len+1)/2];

        for(int i=0; i<=(len+1)/2-1; i++) tempA[i] = a[i];
        for(int i=(len+1)/2,j = 0; i<=len-1; i++, j++) tempB[j] = a[i];

        int[] sortedA = sort(tempA);
        int[] sortedB = sort(tempB);
        int[] Final =  merge(sortedA, sortedB);

        return Final;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];

        for(int i=0; i<=n-1; i++)   a[i] = sc.nextInt();
        int[] c = sort(a);
        for(int i=0; i<c.length; i++)   System.out.print(c[i]+" ");
        
        sc.close();


    }
    
}
