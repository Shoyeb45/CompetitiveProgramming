import java.util.Scanner;
fun main() {
    val sc = Scanner(System.`in`)
    var tt: Int = sc.nextInt();

    while(tt-- > 0) {
        var n = sc.nextInt();
        var r5 = n % 5;
        var r3 = n % 3;
        if((5 - r5) + (3 - r3) == 3 || (5 - r5) + (3 - r3) == 5 || r5 == 0 || r3 == 0) {
            println(0)
        } else {
            if(r5 >= r3) {
                println(r3)
            } else {
                println(r5)
            }
        }
    }
}