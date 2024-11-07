#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
ll k;
vector<ll> a;

void solve() {
    cin >> n >> k;
    a.resize(n);
    for (auto &x : a) {
        cin >> x;
    }    

    ll ans = k + 1;

    for (int i = 1; i < n; i++) {
        ll extendCost = a[i] - a[i - 1];
        ans += min (extendCost, 1LL * k + 1);
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