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

int f(int n) {
    return n * (3 * n - 1) / 2;
}
bool is_sq_num(int x) {
    int sqr_t = (int) sqrt(x);
    return sqr_t * sqr_t == x;
}

void solve() {
    int ans = INT_MAX;
    for (int i = 2; i <= 10000; i++) {
        for (int j = 1; j < i; j++) {
            int x = f(i) - f(j);
            int y = f(i) + f(j);
            if (is_sq_num(24 * y + 1) && is_sq_num(24 * x + 1)) {
                ans = min(ans, x);
            }
        }
    }   
    cout << ans << "\n";
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}