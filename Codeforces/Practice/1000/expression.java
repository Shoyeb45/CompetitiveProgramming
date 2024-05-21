import java.util.*;

public class expression {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int[] ans = new int[6];
        ans[0] = (a + b) * c;
        ans[1] = a + (b * c);
        ans[2] = (a * b) + c;
        ans[3] = a * (b + c);
        ans[4] = a * (b * c);
        ans[5] = a + (b + c);
        Arrays.sort(ans);
        System.out.println(ans[5]);

        sc.close();
    }
}
