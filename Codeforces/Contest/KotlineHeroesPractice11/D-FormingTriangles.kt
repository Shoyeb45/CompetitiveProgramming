import java.util.Scanner;


fun solve(sc: Scanner) {
	var n = sc.nextInt();
	var a: MutableList<Long> = mutableListOf();
	var mp: MutableMap<Long, Long> = mutableMapOf();

	for(i in 1..n) {
		var x = sc.nextLong();
		mp[x] = mp.getOrDefault(x, 0L) + 1;
		a.add(x);
	}
	a = a.sorted().toMutableList();
	var ans: Long = 0L;
	for(i in 0..n-1) {
		val cnt = mp[a[i]]!! - 1;
		
		if(cnt > 0) {
			mp[a[i]] = cnt;
		}
		else {
			mp.remove(a[i]);
		}
		ans += (i * cnt);
	}

	println(ans);
}

fun main() {
	val sc = Scanner(System.`in`);
	var tt = sc.nextInt();

	while(tt-- > 0) {
		solve(sc);
	}
