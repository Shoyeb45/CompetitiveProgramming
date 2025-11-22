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
    vector<int> a(n + 1), b(n + 1);

    int _xor = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        _xor ^= a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        _xor ^= b[i];
    }

    if (_xor == 0) {
        cout << "Tie\n";
        return;
    } 
    int sign_bit = 0;

    for (int i = 30; i >= 0; i--) {
        int mask = (1 << i);
        ll bit = (ll) (mask & _xor);
        if (bit == 0) continue;
        sign_bit = i;
        break;
    }

    int mask = (1 << sign_bit);
    for (int i = n; i >= 1; i--) {
        bool bit1 = (mask & a[i]), bit2 = (mask & b[i]);
        if (bit1 == bit2) continue;
        cout << ((i & 1) ? "Ajisai" : "Mai") << "\n";
        break;
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
        solve();
    }

    return 0;
}