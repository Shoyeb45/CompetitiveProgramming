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
    vector<int> p(n);
    
    for (int &x: p) {
        cin >> x;
    }
    string s;
    cin >> s;
    if (s[0] == '1' || s[n - 1] == '1') {
        cout << -1 << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && (p[i] == 1 || p[i] == n)) {
            cout << -1 << "\n";
            return;
        }
    }
    int pos_1 = -1, pos_n = -1;
    for (int i = 0; i < n; i++) {
        if (p[i] == 1) {
            pos_1 = i;
        } else if (p[i] == n) {
            pos_n = i;
        }
    }

    cout << 5 << "\n";
    cout << 1 << " " << pos_1 + 1 << "\n";
    cout << 1 << " " << pos_n + 1 << "\n";
    cout << pos_n + 1 << " " << n << "\n";
    cout << pos_1 + 1 << " " << n << "\n";
    cout << min(pos_1, pos_n) + 1 << " " << max(pos_1, pos_n) + 1 << "\n";

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