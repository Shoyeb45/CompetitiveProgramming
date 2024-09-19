import java.util.Scanner;

fun solve(sc: Scanner) {
    var n = sc.nextInt();
    var a: MutableList<Int> = mutableListOf();
    for(i in 0..n - 1) {
        var x = sc.nextInt();
        a.add(x);
    }

    var first = 1;
    var last = 1;
    var firInd = a.first()
    var lasInd = a.last();

    var i = 0;

    while(i < n - 1 && a[i] == a[i + 1]) {
        i++;
        first++;
        firInd = a[i];
    }

    i = n - 1;
    while(i >= 1 && a[i] == a[i - 1]) {
        i--;
        last++;
        lasInd = a[i];
    }

    if(first == n) {
        println(0);
    }
    else if(firInd == lasInd) {
        println(n - (first + last));
    }
    else {
        println(n - Math.max(first, last));
    }
}
fun main() {
    val sc = Scanner(System.`in`);
    var tt: Int = sc.nextInt();

    while(tt-- > 0) {
        solve(sc);
    }
}