import java.util.*;

public class pleasantPairs {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        
        for (int i = 0; i < t; i++) {
            int count = 0;
            int n = sc.nextInt();

            int[] arr = new int[n];
            for (int j = 0; j < n; j++) {
                arr[j] = sc.nextInt();
            }

            for (int k = 0; k < n; k++) {
                for (int j = k + 1; j < n; j++) {

                    if (k < j && (long) arr[k] * arr[j] == (long) k + j + 2) {
                        count += 1;
                    }
                }
            }
            System.out.println(count);
        }

        
        sc.close();
    }
}
