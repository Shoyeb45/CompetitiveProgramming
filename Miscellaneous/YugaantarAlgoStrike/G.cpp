#include <bits/stdc++.h>
// vivaanpc
using namespace std;
// vivaanpc
typedef long long ll;
const int mod = 1e9 + 7;
const double eps = 1e-12;

ll div(int nr) {
    if (nr == 1) return 1;
    return nr / 2;
}

void solve() {
    int n;
    cin >> n;
    ll ans = n;
    ll gap = 0;
    ll nr = (6 * n + 1 - (3 * gap));

    while (nr > 0) {
        cout << div(nr) << " ";
        ans = (ans + div(nr)) % mod;
        gap++;

        nr = (6 * n + 1 - 3 * gap);
        
        if (div(nr) == 0) {
            cout << div(nr) << " ";
            ans++;
            ans %= mod;
            break;
        }
    }
    
    cout << ans << "\n";
}

// vivaanpc
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}