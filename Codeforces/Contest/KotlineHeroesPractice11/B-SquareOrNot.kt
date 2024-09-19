import java.util.Scanner;

fun allOne(s: String): Boolean {
    for(ch in s) {
        if(ch == '0') {
            return false;
        }
    }
    return true;
}
fun solve(sc: Scanner) {
    var n: Int = sc.nextInt();
    var s: String = sc.next();

    if(allOne(s)) {
        if(n == 4) {
            println("YES");
            return;
        }
        else {
            println("NO");
            return;
        }
    }
    var ind: Int = 0;

    for(i in 0..n-1) {
        if(s[i] == '0') {
            ind = i + 1;
            break;
        }
    }
    var col: Int = ind - 2;
    var row: Int = n / col;
    
    if(col == row) {
        println("YES");
    }
    else {
        println("NO");
    }
}
fun main() {
    val sc = Scanner(System.`in`);
    var tt = sc.nextInt();

    while(tt-- > 0) {
        solve(sc);
    }
}