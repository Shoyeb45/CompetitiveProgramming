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

void solve() {
    int n;
    ll k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (ll &x: a) {
        cin >> x;
    }   
    sort(range(a));

    vector<ll> diff;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] > x) {
            diff.push_back(a[i] - a[i - 1]);
        }
    }
    sort(range(diff));
    ll ans = (ll) diff.size() + 1;
    for (auto d: diff) {
        if ((d - 1) / x <= k) {
            ans--;
            k -= (d - 1) / x;
        }
        if (k <= 0) {
            break;
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

    while (tt--) {
        solve();
    }

    return 0;
}