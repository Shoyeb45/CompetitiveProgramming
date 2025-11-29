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
    ll k;
    cin >> n >> k;

    multiset<ll> q, r;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        q.insert(x);
    }
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        r.insert(x);
    }

    ll ans = 0;

    // qj * y + rj
    while (!q.empty() && !r.empty()) {
        ll qj = *q.begin();
        ll rj = *r.begin();
        
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
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}