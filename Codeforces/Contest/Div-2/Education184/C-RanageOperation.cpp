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
    vector<ll> pref(n + 1);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
        pref[i + 1] = pref[i] + a[i];
    }

    vector<ll> c(n + 2, LLONG_MIN);
    for (int i = 1; i <= n; i++) {
        c[i] = (ll) i * i - pref[i] + i;
    }
    
    for (int i = n - 1; i >= 1; i--) {
        c[i] = max(c[i], c[i + 1]);
    }

    ll temp = 0;
    for (int i = 1; i <= n; i++) {
        ll d = i - (ll) i * i + pref[i - 1];
        ll suff = c[i];
        temp = max(suff + d, temp); 
    }
    cout << ans + temp << "\n";
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
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}