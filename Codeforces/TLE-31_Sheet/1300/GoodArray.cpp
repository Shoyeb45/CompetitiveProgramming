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
    cin >> n;
    vector<ll> a(n + 1);
    ll sum = 0;
    vector<ll> pref_max(n + 1, LLONG_MIN), suff_max(n + 2, LLONG_MIN);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        pref_max[i] = max(pref_max[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--) {
        suff_max[i] = max(suff_max[i + 1], a[i]);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        ll mx = max(pref_max[i - 1], suff_max[i + 1]);
        ll temp = sum - a[i];
        debug(a[i], mx, temp);
        if (2LL * mx == temp) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << '\n';
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