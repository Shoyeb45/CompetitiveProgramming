

import java.util.Scanner;

public class q6 {
    public static int GCD(int a, int b){
        if(b == 0)
        return a;

        return GCD(b, a % b);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.print("GCD("+a+","+b+") = "+GCD(a, b));
        sc.close();
    }
    
}
