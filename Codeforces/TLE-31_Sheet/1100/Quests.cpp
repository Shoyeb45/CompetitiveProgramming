#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, k;
vector<int> a, b;
void solve() {
    cin >> n >> k;
    a.resize(n), b.resize(n);
    for(auto &x: a) {
        cin >> x;
    }
    for(auto &x: b) {
        cin >> x;
    }


    ll ans = 0, mx = 0, sum = 0;

    for(int i = 0; i < min(n, k); i++) {
        mx = max(mx, 1LL * b[i]);
        sum += a[i];
        ans = max(ans, sum + mx * (k - i - 1));
    }

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