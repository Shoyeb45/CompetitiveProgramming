#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS                                                                                                            \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

bool is_overlapping(vector<int> &i1, vector<int> &i2) {
    return !(i1[1] < i2[0] || i2[1] < i1[0]);
}

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> mn_q, mex_q;

    while (q--) {
        int c, l, r;
        cin >> c >> l >> r;
        if (c == 1) {
            mn_q.push_back({l, r});
        } else {
            mex_q.push_back({l, r});
        }
    }

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) 
        ans[i] = i % k;

    for (auto &x : mn_q)
        for (int i = x[0]; i <= x[1]; i++)
            ans[i] = k;

    for (auto &x : mex_q) {
        int l = x[0], r = x[1];

        for (int i = l; i <= r; i++) {
            if (ans[i] == k) 
                ans[i] = k + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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
