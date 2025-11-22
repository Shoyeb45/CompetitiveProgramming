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
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    int aj = 0, m = 0;
    for (int i = 1; i <= n; i++) {
        aj += a[i];
        m += b[i];
    }

    aj = (aj % 2), m = (m % 2);
    debug(aj, m);
    for (int i = 1; i <= n; i++) {
        if ((a[i] == 0 && b[i] == 0) || ((a[i] == 1) && (b[i] == 1))) continue;

        if (i % 2 == 1) {
            if (aj == 0) {
                aj = 1, m = 1 - m;
            }    
        } else {
            if (m == 0) {
                m = 1, aj = 1 - aj;
            }
        }
    }
    if (aj % 2 == m % 2) {
        cout << "Tie\n";
        return;
    }
    cout << (aj == 1 ? "Ajisai" : "Mai") << "\n";
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