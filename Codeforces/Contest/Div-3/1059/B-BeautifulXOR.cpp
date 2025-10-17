#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
const ll mod = 1000000007;

void solve() {
    int x, y;
    cin >> x >> y;
    vector<int> ans;
    
    for (int i = 0; i <= 30; i++) {
        int mask = (1 << i);
        bool bit1 = (bool) (mask & x);
        bool bit2 = (bool) (mask & y);
        if (bit1 != bit2) {
            if (mask > x) {
                cout << -1 << "\n";
                return;
            }
            ans.push_back(mask);
            x ^= mask;
        }
    }

    cout << ans.size() << "\n";
    debug(x);
    for (auto p: ans) {
        // x ^= p;
        cout << p << " ";
    }
    cout << "\n";
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