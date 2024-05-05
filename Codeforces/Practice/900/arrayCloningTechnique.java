import java.util.Arrays;
import java.util.Scanner;

public class arrayCloningTechnique {
    public static int maxFreq (int[] a, int len) {
        Arrays.sort(a);
        int i = 0, maxFreq = 0; 
        while (i < len) {
            int freq = 1;
            while(i + 1 < len && a[i] == a[i+1]){
                freq++;
                i++;
            }

            if(maxFreq <= freq) {
                maxFreq = freq;
            }
            i++;
        }
        return maxFreq;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        for(int p=1; p<=t ; p++) {
            int n = sc.nextInt();

            int[] a = new int[n];
            for(int i=0; i<=n-1; i++)
                a[i] = sc.nextInt();
            int x = maxFreq(a, n);
            int ope = 0;
            if(x == n){
                System.out.println(0);
            } else {
            for(int i=x ; ; i *= 2){
                if(2 * i < n){
                    ope += (1 + i);
                } else {
                    ope += (1 + (n - i));
                    break;
                }
            }
            System.out.println(ope);
        }
            
        }
        sc.close();
    }
}
