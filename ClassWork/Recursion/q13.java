package ClassWork.Recursion;

import java.util.Scanner;

public class q13 {
    public static int occurence(int arr[], int a, int len, int i){
        if(i == len - 1 && arr[i] == a)
        return 1;

        if(arr[i] == a){
            return 1+occurence(arr, a, len, i+1);
        }
        return 0+occurence(arr, a, len, i+1);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        
        int a = sc.nextInt();
        System.out.println(occurence(arr, a, n, 0));
        sc.close();
    }
}
