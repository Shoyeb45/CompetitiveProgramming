import java.util.*;

public class showStopper {
    public static int max(int[] a, int l) {
        int max = a[0];

        for(int i = 0; i<l; i++){
            if(a[i] >= max)
            max = a[i];
        }
        return max;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        for(int i = 1; i<=t; i++){
            int n = sc.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];
                for(int j = 0; j<n; j++){
                    a[j] = sc.nextInt();
                }
                for(int j = 0; j<n; j++){
                    b[j] = sc.nextInt();
                }
                
                int maxa = 0 , maxb = 0;
                for (int j = 0; j<n ; j++){
                    if(a[j] > b[j]){
                        int temp = a[j];
                        a[j] = b[j];
                        b[j] = temp;
                    }
                    if(maxa < a[j])
                    maxa = a[j];
                    if(maxb < b[j])
                    maxb = b[j];
                }
                if(maxa == a[n-1] && maxb == b[n-1])
                System.out.println("YES");
                else
                System.out.println("NO");
        }
        sc.close();
    }   
}
