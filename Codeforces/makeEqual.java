import java.util.Arrays;
import java.util.Scanner;

public class makeEqual {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            int[] water = new int[n];

            for(int j=0; j<n; j++)  water[j] = sc.nextInt();

        if(n != 1) {    
            int[] sorted = new int[n];
            Arrays.sort(sorted);
            int median = 0;
            if(n % 2 != 0) median = sorted[n/2];
            else           median = (sorted[n/2] + sorted[n/2 - 1])/2 ;
            
        }
            
        }
        sc.close();
    }
}
