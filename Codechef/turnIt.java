// package Codechef;

import java.util.*;

public class turnIt {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int a = sc.nextInt();
            int s = sc.nextInt();

            if(u > v) {
                if(( u * u - 2 * a * s) <= v * v)
                System.out.println("Yes");
                else
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }
        }
        sc.close();
    }
}
