import java.util.Scanner;

public class luckyString {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] arr = {'a', 'b', 'c', 'd'};
        int i = 0;

        while (n-- > 0) {
            if (i >= 4) {
                i = i % 4;
            }
            System.out.print(arr[i]);
            i++;
        }

        sc.close();
    }
}

