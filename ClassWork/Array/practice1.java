// inserting one element in sorted array

package Array;

import java.util.Scanner;

public class practice1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n+1];
        for(int i = 0 ; i<=n-1; i++){
            arr[i] = sc.nextInt();
        }
        int m = sc.nextInt();

        for(int i = 0 ; i<=n; i++){
            if(arr[i] > m){
                for(int j = n-1; j>=i; j--){
                    arr[j+1] = arr[j];
                }
                arr[i] = m;
                break; 
            }
        }

        for(int i = 0 ; i<=n; i++){
            System.out.print(arr[i]+" ");
        }
        

        sc.close();

    }
    
}
