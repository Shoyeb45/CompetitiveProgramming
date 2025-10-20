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
ll dp[36][251];
vector<ll> value, weight;
int mx_weight, n;

ll f(int idx, ll wt) {
    if (idx >= n) {
        return 0;
    }
    if (wt <= 0) {
        return 0;
    }
    if (dp[idx][wt] != -1) {
        return dp[idx][wt];
    }
    ll not_pick = f(idx + 1, wt);
    ll pick = INT_MIN;
    if (wt - weight[idx] >= 0) {
        pick = value[idx] + f(idx, wt - weight[idx]);
    }

    return dp[idx][wt] = max(pick, not_pick);
}

void solve() {
    cin >> mx_weight >> n;
    value.reserve(n), weight.reserve(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        ll w, v;
        cin >> w >> v;
        value.push_back(v), weight.push_back(w); 
    }

    cout << f(0, mx_weight) << "\n";
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