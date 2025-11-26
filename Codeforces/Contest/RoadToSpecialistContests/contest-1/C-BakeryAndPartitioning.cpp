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
    int _xor = 0;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        _xor ^= a[i];
    }

    vector<vector<int>> adj(n + 1);

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (_xor == 0) {
        cout << "YES\n";
        return;
    }

    if (k - 1 < 2) {
        cout << "NO\n";
        return;
    }

    int edges = 0;
    std::function<int(int, int)> dfs = [&](int u, int parent) -> int {
        int overall_xor = a[u];
        debug(u);
        for (int& v: adj[u]) {
            if (v != parent) {
                int temp = dfs(v, u);
                overall_xor ^= temp;
            }
        }
        edges += (overall_xor == _xor);
        return (overall_xor == _xor ? 0: overall_xor);
    };

    dfs(1, -1);

    if (edges < 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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