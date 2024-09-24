#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, m;
void solve() {
    cin >> n >> m;

    vector<ll> a(n), b(m);

    for(auto &x: a) {
        cin >> x;
    }

    for(auto &x: b) {
        cin >> x;
    }

    ll pre = 0;
    for(int i = 0; i < n - 1; i++) {
        pre = __gcd( pre, abs(a[i] - a[i + 1]) );
    }

    for(auto x: b) {
        cout << __gcd(x + a[0], pre) << " ";
    }
    cout << '\n';
    
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
