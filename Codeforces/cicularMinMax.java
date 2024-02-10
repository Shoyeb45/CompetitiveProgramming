import java.util.Arrays;
import java.util.Scanner;

public class cicularMinMax {
    public static void swap(int[] a, int i, int j){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        for(int p=1; p<=t; p++){
            int n = sc.nextInt();

            int[] arr = new int[n];

            for(int i=0; i<=n-1; i++)
                arr[i] = sc.nextInt();
            Arrays.sort(arr);

            for(int i=1; i<=n-2; ){
                if(arr[i] == arr[i+1]){
                    int idx = 0;
                    for(int j=i+1; j<=n-1 ;j++){
                        if(arr[j] == arr[i]){
                            idx = j;
                            break;
                        }
                    }
               
                    for(int j=idx; j>=i; j--){
                        if(j+1 != n)
                        swap(arr, j+1, j);
                    }
                    
                    i = i + 2;
                } else {
                    swap(arr, i, i+1);
                    i = i + 2;
                }
            }

            if(arr[0] == arr[n-1] || arr[n-1] == arr[n-2])
                System.out.println("NO");   
            else{
                if((arr[0] < arr[1] && arr[0] < arr[n-1]) && ( (arr[n-1] < arr[n-2] && arr[n-1] < arr[0]) || (arr[n-1] > arr[n-2] && arr[n-1] > arr[0])) ){
                System.out.println("YES");
                for(int i = 0; i<=n-1; i++)
                    System.out.print(arr[i]+" ");
                    System.out.println();
                } else {
                    System.out.println("NO");
                }
            }
        }
        sc.close();
    }
}
