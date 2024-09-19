import java.util.Scanner;

fun main() {
    val sc = Scanner(System.`in`);
    var tt = sc.nextInt();

    while(tt-- > 0) {
        var a: Int = sc.nextInt();
        var b: Int = sc.nextInt();

        println("${Math.min(a, b)} ${Math.max(a, b)}");
    }
}