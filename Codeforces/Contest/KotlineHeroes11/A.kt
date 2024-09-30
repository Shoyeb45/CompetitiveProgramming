import java.util.Scanner;


fun solve(sc: Scanner) {
    var n = sc.nextInt();
    var a: MutableList<Int> = mutableListOf();
    for(i in 0..n - 1) {
        var x = sc.nextInt();
        a.add(x);
    }

    var mx: Int = -100000000;
    for(i in 0..n - 2) {
        mx = Math.max(a[i], mx);
    }

    if(a[n - 1] - mx == 1) {
        println(mx);
    }
    else {
        println("Ambiguous");
    }
    
}
fun main() {
    val sc = Scanner(System.`in`);
    var tt = sc.nextInt();

    while(tt-- > 0) {
        solve(sc);
    }
}