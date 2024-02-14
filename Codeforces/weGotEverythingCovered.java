import java.util.Scanner;

public class weGotEverythingCovered {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int p=1; p<=t; p++) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            // if (n <= k) {
                // for(int i=1; i<=n ; i++) {
                //     for(int j=1; j<=k; j++) {
                //         System.out.print((char)(96 + j));
                //     }
                // }
            // } 
            String strt = "abcdefghijklmnopqrstuvwxyz";
            String m = strt.substring(0, k);
            for(int i=1; i<=n; i++) {
                System.out.print(m);
            }
            System.out.println();
        }
        sc.close();
    }
}
