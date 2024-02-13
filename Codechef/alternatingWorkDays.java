package Codechef;
import java.util.*;
public class alternatingWorkDays {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int o=1; o<=t; o++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int p = sc.nextInt();
            int q = sc.nextInt();

            boolean ans = false;
            for(int i = 1; i<=(2 * q)/a || i <= 2 * ((9/a) - 1); i += 2) {
                if ( ((i/2 + 1) * a == p && (i+1)/2 * b == q) || ((i/2 + 1) * a == q && (i+1)/2 * b == p) ) {
                    ans = true;
                    break;
                } else {
                    ans = false;
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
