#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll n;
ll sumOfSq(ll n) {
    ll a = n * (n + 1) % mod;
    ll b = ((2 * n) % mod) + 1;

    return ((((a * b) % mod * 1LL * n) / 6) % mod) % mod;
}
void solve() {
    cin >> n;

    ll ans = ( ((n * (n + 1)) % mod) * ((4 * n - 1)) % mod * 337LL) % mod;
 
    cout << ans << "\n";
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}