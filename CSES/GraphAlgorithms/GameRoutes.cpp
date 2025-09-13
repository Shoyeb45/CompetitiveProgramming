#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

// This is simple one, use DP on DAG, count all the path from node i -> n, and memoize the state.

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }   

    vector<ll> dp(n + 1, -1);
    std::function<ll(int)> dfs = [&](int u) -> ll {
        if (u == n) {
            return dp[u] = 1;
        }
        if (dp[u] != -1) {
            return dp[u];
        }
        ll ans = 0;
        for (int &v: adj[u]) {
            ll x = dfs(v) % mod;
            ans = (ans + x) % mod;
        }
        return dp[u] = ans % mod;
    };
    cout << dfs(1) % mod << "\n";
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