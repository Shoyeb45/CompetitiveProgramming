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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int& x: a) cin >> x;

    
    // vector dp(n + 1, vector<int>(x + 1, INT_MAX));

    // dp[n][0] = 0;

    // for (int s = 1; s <= x; s++) dp[n][s] = INT_MAX;

    // for (int i = n - 1; i >= 0; i--) {
    //     for (int s = 0; s <= x; s++) {
    //         dp[i][s] = dp[i + 1][s]; // skip

    //         if (s >= a[i]) {
    //             int temp = min(dp[i + 1][s - a[i]], dp[i][s - a[i]]);
    //             if (temp != INT_MAX) {
    //                 dp[i][s] = min(dp[i][s], 1 + temp);
    //             }
    //         }
    //     }
    // }

    vector<int> dp(x + 1);

    dp[0] = 0;

    for (int s = 1; s <= x; s++) {
        dp[s] = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (s - a[j] >= 0) {
                if (dp[s - a[j]] != INT_MAX)
                    dp[s] = min(dp[s], dp[s - a[j]] + 1);
            }
        }
    }
    int ans = dp[x];

    cout << (ans == INT_MAX ? -1 : ans) << "\n";
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
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}