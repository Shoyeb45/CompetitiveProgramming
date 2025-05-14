#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


int a, b;
void solve() {
	cin >> a >> b;

	if (a == b) {
		cout << "infinity\n";
		return;
	}
	if (a < b) {
		cout << 0 << "\n";
		return;
	}

	ll ans = 0;
	ll num = (ll)(a - b);

	for (ll i = 1; 1LL * i * i <= num; i++) {
		// debug("i", i);
		if (num % i == 0) {
			int div2 = num / i;
			if (div2 == i && i > b) {
				ans++;
			}
			else if (div2 > b && i > b) {
				ans += 2;
			}
			else if (div2 > b || i > b) {
				ans++;
			}
		}		
	}

	cout << ans << "\n";

}   

int main() {
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}