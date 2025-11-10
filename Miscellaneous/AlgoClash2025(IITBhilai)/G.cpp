#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll dot_prodcut(array<ll, 6> &a, array<ll, 6> &b) {
    ll ans = 0;
    for (int i = 0; i < 5; i++) {
        ans += 1LL * a[i] * b[i];
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<array<ll, 6>> a(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
        a[i][5] = dot_prodcut(a[i], a[i]);
    }
    vector<int>;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll num = dot_prodcut(a[i], a[j]);
            ll den = a[i][5] * a[j][5];
            ll arg = ((double) num) / ((double) den);
            ll angle = 2 * acos(arg);
            if (angle - M_PI >= DBL_EPSILON) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    #endif
    int tt;
    tt = 1;
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}