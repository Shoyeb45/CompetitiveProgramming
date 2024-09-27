import java.util.Scanner;

public class reactangleCutting {
    public static int abso(int a, int b) {
        if(a - b > 0)
            return a-b;
        return b - a;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int a = sc.nextInt(); 
            int b = sc.nextInt();
            boolean ans =false;
            if(a <= 1 && b <= 1) {
                ans = false;
            } else if ( a % 2 == 0 && b % 2 == 0) {
                ans = true;
            } else if ( a % 2 != 0 && b % 2 != 0) {
                ans = false;
            } else if ( a % 2 == 0 && b % 2 != 0) {
                if(abso(a, b) == b) 
                    ans = false;
                else
                    ans = true;
            } else if ( a % 2 != 0 && b % 2 == 0) {
                if(abso(a, b) == a) 
                    ans = false;
                else
                    ans = true;
            }
            if(ans)     System.out.println("YES");
            else        System.out.println("NO");
        }
        sc.close();
    }
}
