import java.util.*;

public class maximiseTheScore {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int p=0 ; p<t; p++) {
            int n = sc.nextInt();
            int[] a = new int[2*n];

            for(int i=0; i<2*n; i++)    a[i] = sc.nextInt();

            Arrays.sort(a);
            int sum = 0;
            for(int i=0 ; i<2*n; i += 2) {
                sum += a[i];
            }
            System.out.println(sum);
        }
        sc.close();
    }
}
