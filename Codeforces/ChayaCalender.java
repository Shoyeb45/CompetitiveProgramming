import java.util.Scanner;

public class ChayaCalender {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            int[] a = new int[n];

            for(int i=0; i<n; i++)  a[i] = sc.nextInt();

            int ans = a[0];

            for(int i=1; i<=n-1; i++) {
                for(int j = a[i];    ; j+=a[i])
                    if(j >= ans+1) {
                    ans = j;
                    break;
                }
            }
            System.out.println(ans);
            
        }
    }
}
