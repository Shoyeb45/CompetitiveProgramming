
import java.util.Scanner;

public class q7 {
    public static int facto(int n){
        if(n == 0 || n == 1)
        return 1;

        return n * facto(n-1);
    }

    // public static float comb(int n, int r){
    //     if(n < r)
    //     return -1;
    //     return facto(n) / (facto(n-r) * facto(r));
    // }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter n, r and m:");
        int n = sc.nextInt();
        int r = sc.nextInt();
        int m = sc.nextInt();

        if(n < r)
        System.out.println("Undefined");
        else
        System.out.println((facto(n) / (facto(n-r) * facto(r))) % m);
        sc.close();
    }
}
