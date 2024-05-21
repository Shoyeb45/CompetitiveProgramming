import java.util.*;

public class CircularLocalMinMax {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int u = 1; u<=t; u++){
            int n = sc.nextInt();
            long[] arr = new long[n];
            for(int i=0; i<=n-1; i++)  
                arr[i] = sc.nextInt();
            
            long[] ans = new long[n];
            Arrays.sort(arr);
            long x = 0, y = 1, i = 0, j = n/2;
            while (i < n/2 && j < n) {
                ans[(int)x] = arr[(int)i];
                ans[(int)y] = arr[(int)j];
                i++;
                j++;
                x = x + 2;
                y = y + 2;
            }

            if( n % 2 != 0)
            ans[n-1] = arr[n-1];
            boolean Ans = true;
            for(int k = 1; k < n-1; k++){
                if(( ans[k] > ans[k+1] && ans[k] > ans[k-1]) || ( ans[k] < ans[k+1] && ans[k] < ans[k-1]) ) {
                    
            } else {
                    Ans = false;
                    break;
                }
            }
            
            if(Ans){
                System.out.println("YES");
                for(int k=0; k<n; k++){
                    System.out.print(ans[k] + " ");
                }
                System.out.println();
            }else 
                System.out.println("NO");
        }

        sc.close();
    }
}
