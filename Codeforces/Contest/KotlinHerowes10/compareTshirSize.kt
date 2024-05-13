import java.util.Scanner;

fun main() {
    val sc = Scanner(System.`in`)
    var tt = sc.nextInt()
    
    while(tt-- > 0) {
        var a: String = sc.next();
        var b: String = sc.next();
        if(a.equals(b)) {
            println("=")
        } else {
            if(a[a.length - 1] == 'L' && b[b.length - 1] != 'L') {
                println(">")
            } else if(a[a.length - 1] == 'S' && b[b.length - 1] != 'S') {
                println("<")
            } else if(a[a.length - 1] == 'M') {
                if(b[b.length - 1] == 'S')
                    println(">")
                else
                    println("<")
            } else {
                var cnt1: Int = 0;
                var cnt2: Int = 0;
                for(ch in a) {
                    if(ch == 'X')
                        cnt1++;
                }
                for(ch in b) {
                    if(ch == 'X')
                        cnt2++;
                }

                if(a[a.length - 1] == b[b.length - 1]) {
                    if(a[a.length - 1] != 'S') {
                        if(cnt1 > cnt2)
                            println(">")
                        else
                            println("<")
                    } else {
                        if(cnt1 > cnt2)
                            println("<")
                        else
                            println(">")
                    }
                }
            }


        }
    }
}