// Merging two sorted array

package ClassWork.Array;

import java.util.Scanner;

public class practice2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] arr1 = new int[n];
        int[] arr2 = new int[m];

        for(int i = 0; i<=n-1; i++){
            arr1[i] = sc.nextInt();
        }
        for(int i = 0; i<=m-1; i++){
            arr2[i] = sc.nextInt();
        }

        int[] c = new int[n+m];

        int k = 0;
        for(int i = 0, j = 0 ; i < n || j < m ;){
            if(i == n){
            c[k] = arr2[j];
            k++;
            j++;
        }
            else if(j == m) {
            c[k] = arr1[i];
            k++;
            i++;
        }
            else if(arr1[i] <= arr2[j]) {
            c[k] = arr1[i];
            k++;
            i++;
        }
            else {
            c[k] = arr2[j];
            k++;
            j++;
        }
        }

        
        
        for(int i= 0; i<=n+m-1; i++){
            System.out.print(c[i]+" ");
        }
    }
    
}
