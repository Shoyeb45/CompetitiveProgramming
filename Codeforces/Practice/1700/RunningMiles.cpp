#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
vector<ll> b;

// Greedy Solution
void solve() {
    cin >> n;
    b.resize(n + 1);
    vector<ll> l(n + 1), r(n + 2, -1e9);
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        l[i] = max(b[i] + i, l[i - 1]);
    }
    for(int i = n; i >= 1; i--) {
        r[i] = max(b[i] - i, r[i + 1]);
    }
    // cout << "b_i + i\n";
    // for(int i = 1; i <= n; i++) {
    //     cout << l[i] << " ";
    // }
    // cout << "\n";
    // cout << "b_i - i\n";
    // for(int i = 1; i <= n; i++) {
    //     cout << r[i] << " ";
    // }
    // cout << "\n";

    ll ans = 0;
    for(int i = 2; i < n; i++) {
        ans = max(ans, b[i] + l[i - 1] + r[i + 1]);
    }
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
