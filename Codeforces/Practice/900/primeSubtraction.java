import java.util.Scanner;

public class primeSubtraction {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();

        for (int i = 1; i <= k; i++) {
            long a = sc.nextLong();
            long b = sc.nextLong();

            if (a % 2 == 0 && b % 2 == 0) {
                System.out.println("YES");
            } else if ((a % 2 == 1 && b % 2 == 0) || (a % 2 == 0 && b % 2 == 1)) {
                if (a - b >= 2)
                    System.out.println("YES");
                else
                    System.out.println("NO");
            } else {
                System.out.println("YES");
            }

        }
        sc.close();
    }
}
