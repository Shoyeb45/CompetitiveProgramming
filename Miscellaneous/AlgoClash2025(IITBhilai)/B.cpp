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
    int n, k;
    cin >> n >> k;
    int ans = INT_MAX;

    for (int x = 0; x <= 50; x++) {
        for (int y = 0; y <= 50; y++) {
            for (int z = 0; z <= 50; z++) {
                for (int w = 0; w <= 50; w++) {
                    int l = 2 * x + 3 * y + 4 * z + 5 * w;
                    if (l == k && x + y + z + w == n) {
                        cout << x << "\n";
                        return;
                    }
                }
            }
        }
    }
    // cout << ans << "\n";

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

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}