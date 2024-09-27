#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll w, h;

ll calculate(ll b) {
    int k;
    cin >> k;
    ll mx = INT_MIN, mn = INT_MAX;

    while(k--) {
        ll x;
        cin >> x;
        mn = min(x, mn);
        mx = max(x, mx);
    }
    
    return b * (mx - mn);
}
void solve() {
    cin >> w >> h;
    
    ll ans = 0;
    
    ans = calculate(h);
    ans = max(calculate(h), ans);
    ans = max(calculate(w), ans);
    ans = max(calculate(w), ans);

    cout << ans << '\n';
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