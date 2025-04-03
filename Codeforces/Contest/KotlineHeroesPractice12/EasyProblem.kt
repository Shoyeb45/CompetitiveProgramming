import java.util.Scanner;


fun main () {
    var sc = Scanner(System.`in`);

    var tt: Int = sc.nextInt();

    while (tt-- > 0) {
        var n = sc.nextInt();

        var ans = 0;

        for (i in 1 until n) {
            if (n - i > 0 && n - i <= n) {
                ans += 1;
            }
        }

        println(ans);
    }
}