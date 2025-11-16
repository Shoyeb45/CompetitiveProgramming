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
    ll n, m;
    cin >> n >> m;
    if (m > n) {
        cout << "NO\n";
        return;
    }
    ll w = max(m, (n + 2) / 2);
    ll lo = n - w;
    debug(w, lo);
    if (w - lo >= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

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
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}