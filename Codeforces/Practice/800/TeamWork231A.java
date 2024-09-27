import java.util.*;

public class TeamWork231A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[][] response = new int[n][3];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                response[i][j] = sc.nextInt();
            }
        }
        int problems = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < 3; j++) {
                if (response[i][j] == 1) {
                    count++;
                }
            }

            if (count >= 2)
                problems++;
        }

        System.out.println(problems);
        sc.close();
    }
}