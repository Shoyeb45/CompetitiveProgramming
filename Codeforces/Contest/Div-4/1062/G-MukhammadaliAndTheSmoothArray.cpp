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

int n;
int a[8001];
ll cost[8001];
ll dp[8001];



void solve() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }    
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }    
    ll sum = 0;
    ll mx_ele = INT_MIN;
    for (int i = 0; i < n; i++) {
        ll mx = INT_MIN;
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[i]) {
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = cost[i] + (mx == INT_MIN ? 0: mx);
        sum += cost[i];
        mx_ele = max(mx_ele, dp[i]);
    }
    cout << sum - mx_ele  << "\n";
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