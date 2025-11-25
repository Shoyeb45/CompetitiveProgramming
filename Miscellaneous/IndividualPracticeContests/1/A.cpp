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
    ll n, h;
    cin >> n >> h;

    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(rrange(a));
    ll sum = a[0] + a[1];
    ll k = (h + sum - 1) / sum;
    debug(k);
    
    if ((1LL * sum * k) - a[1] >= h) {
        cout << (ll) 2 * k - 1 << "\n";
        return;
    }
    debug(2 * k);
    cout << 2 * k << "\n";
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
    debug(tt);
    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}