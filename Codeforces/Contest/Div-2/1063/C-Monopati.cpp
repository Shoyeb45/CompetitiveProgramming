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
    vector a(2, vector<int> (n));
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            cin >> a[j][i];
        }
    }   
    
    vector pref(2, vector<int> (n + 1, INT_MIN)); // 0 -> max, 1 -> min of a[0]
    
    for (int i = 1; i <= n; i++) {
        pref[0][i] = max(pref[0][i - 1], a[0][i - 1]);
    }
    
    fill(range(pref[1]), INT_MAX);
    
    for (int i = 1; i <= n; i++) {
        pref[1][i] = min(pref[1][i - 1], a[0][i - 1]);
    }
    
    vector suff(2, vector<int> (n + 2, INT_MIN)); // 0 -> max, 1 -> min of a[1]

    for (int i = n; i >= 1; i--) {
        suff[0][i] = max(suff[0][i + 1], a[1][i - 1]);
    }
    
    fill(range(suff[1]), INT_MAX);
    for (int i = n; i >= 1; i--) {
        suff[1][i] = min(suff[1][i + 1], a[1][i - 1]);
    }


    vector<int> f(2 * n + 1, 2 * n + 1);

    for (int i = 1; i <= n; i++) {
        int x = min(pref[1][i], suff[1][i]);
        int y = max(pref[0][i], suff[0][i]);
        f[x] = min(f[x], y);
    }


    ll ans = 0;
    for (int i = 2 * n - 1; i >= 1; i--) {
        f[i] = min(f[i], f[i + 1]);
    }
    for (int i = 1; i <= 2 * n; i++) {
        ans += 2 * n - f[i] + 1;
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
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}