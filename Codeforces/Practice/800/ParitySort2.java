import java.util.Arrays;
import java.util.Scanner;

public class ParitySort2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            int[] a = new int[n];
            int[] sorted = new int[n];

            int Count = 0;
            for(int i=0; i<=n-1; i++) {
                a[i] = sc.nextInt();
                sorted[i] = a[i];
            }

            Arrays.sort(sorted);
            for(int i=0; i<=n-1; i++) {
                if( (a[i] % 2 == 0 && sorted[i] % 2 == 0) || (a[i] % 2 != 0 && sorted[i] % 2 != 0))
                Count++;
            }

            if(Count == n)
                System.out.println("YES");
            else
                System.out.println("NO");
        }

        sc.close();
    }
}
