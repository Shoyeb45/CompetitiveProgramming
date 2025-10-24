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
const int N = 3e5 + 1;


void solve() {
    int n;
    char ch;
    string s;
    cin >> n >> ch >> s;

    set<int> idxs;
    for (int i = 0; i < n; i++) {
        if (s[i] != ch) {
            idxs.insert(i + 1);
        }
    }
    debug(idxs);
    if (idxs.empty()) {
        cout << 0 << "\n";
        return;
    }
    if (*idxs.rbegin() != n) {
        cout << 1 << "\n" << n << "\n";
        return; 
    }

    
    for (int p = 2; p <= n; p++) {
        bool ok = true;
        for (int j = p; j <= n; j += p) {
            if (idxs.find(j) != idxs.end()) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << 1 << "\n" << p << "\n";
            return;
        }
    }

    cout << 2 << "\n" << 2 << " " << (n % 2 == 0 ? n - 1: n) << "\n";
    
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

    while (tt--) {
        solve();
    }

    return 0;
}