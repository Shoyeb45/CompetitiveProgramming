import java.util.Arrays;
import java.util.Scanner;

public class makeIItBeautiful {
    public static boolean isBeautiful(int[] a, int len){
        if (a[0] == 0 || a[0] == a[1])
            return false;

        for (int i = 1; i < len; i++) {
            int sum = 0;
            for (int j = 0; j < i; j++) {
                sum += a[j];
            }
            if (sum == a[i])
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        for(int i=1; i<=t; i++){
            int n = sc.nextInt();
            int[] a = new int[n];
            for(int j=0; j<n; j++) {
                a[j] = sc.nextInt();
            }
            if(isBeautiful(a, n)) {
                System.out.println("YES");
                for(int j=0; j<n; j++){
                    System.out.print(a[j]+" ");
                }
                System.out.println();
            } else {
                Arrays.sort(a);

                for(int k = 1; k<=n-1; k++) {
                    int sum = 0;
                    for(int p = 0; p<k; p++){
                        sum += a[p];
                    }

                    if(sum == a[k]){
                        if(k+1 != n){
                        int temp = a[k+1];
                        a[k+1] = a[k];
                        a[k] = temp;
                    }else{
                        int temp = a[k-1];
                        a[k-1] = a[k];
                        a[k] = temp;

                    }
                    }
                    if(isBeautiful(a, n)){
                        System.out.print("YES\n");
                for(int h = 0 ; h<=n-1; h++){
                    System.out.print(a[h] + " ");
                }
                break;
                    }
                }

                // if(isBeautiful(a, n)){
                //     System.out.print("YES\n");
                // for(int h = 0 ; h<=n-1; h++){
                //     System.out.print(a[h] + " ");
                // }
                System.out.println();
            if(!isBeautiful(a, n)) {
                System.out.println("NO");
            }
            }
        }
    }
    
}
