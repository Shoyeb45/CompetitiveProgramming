import java.util.Scanner;

fun main() {
    var sc = Scanner(System.`in`);
    var tt = sc.nextInt();

    while(tt-- > 0) {
        var n: Int = sc.nextInt();
        var a = IntArray(n);
        for(i in 0..n-1) {
            a[i] = sc.nextInt();
        }
        var idx = n;
        if(a[0] != a[1] && a[0] != a[2]) {
            idx = 1;
        } else {
            for(i in 1..n-1) {
                if(a[0] != a[i]) {
                    idx = i + 1;
                }
            }
    
        }
        
        println(idx)
    }
}