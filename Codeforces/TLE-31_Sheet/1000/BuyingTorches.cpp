#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll x, y, k;
void solve() {
    cin >> x >> y >> k;
    
    ll ans = k;
    ll want = (y + 1) * k - 1;

    ans += (want + x - 2) / (x - 1);
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