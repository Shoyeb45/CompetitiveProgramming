package Codechef;
import java.util.*;

public class findingShoes {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=0; p<t; p++) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            if( m - n >= 0 ) {
                System.out.println(n);
            } else {
                System.out.println(2*n - m);
            }
        }
        sc.close();
    }
}
