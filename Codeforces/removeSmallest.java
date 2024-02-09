
import java.util.*;

public class removeSmallest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        for(int i = 1; i<=t; i++){
            int n = sc.nextInt();
            int[] a = new int[n];
            for(int j = 0 ; j<n; j++){
                a[j] = sc.nextInt();
            }
            Arrays.sort(a);
            boolean ans = true;
            for(int k = 1; k<n; k++){
                if(a[k] - a[k-1] > 1){
                    ans = false;
                    break;                 
                }
            }
            if(ans)
            System.out.println("YES");
            else
            System.out.println("NO");
        }
        
        sc.close();
    }
    
}
