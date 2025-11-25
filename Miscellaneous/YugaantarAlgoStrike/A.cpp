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
    vector<ll> a(n);

    for (ll &x: a) cin >> x;

    vector<ll> pref(n), suff(n);

    pref[0] = 1, suff[n - 1] = 1;

    for (int i = 1; i < n; i++) {
        pref[i] = 1;
        if ((a[i] > a[i - 1])) 
            pref[i] += pref[i - 1];
    }

    for (int i = n - 2; i >= 0; i--) {
        suff[i] = 1;
        if (a[i] > a[i + 1]) 
            suff[i] += suff[i + 1];
    }

    ll ans = 0;
    debug(suff);
    debug(pref);

    for (int i = 1; i < n - 1; i++) {
        if (a[i] > a[i + 1] && pref[i] >= 2)
            ans = max(ans, pref[i] + suff[i + 1]);
    }
    cout << ans << "\n";
}   



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif
    int tt;
    tt = 1;
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}