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

// ** use array whenever possible. **
// This is dp bitmasking question.

vector<int> adj[22];
ll dp[(1 << 21)][22];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
    }   
    memset(dp, -1, sizeof dp);

    function<ll(int, int)> dfs = [&](int mask, int u) -> ll {
        mask = (mask ^ (1 << u)); // mark visited
        if (u == n - 1) {
            return dp[mask][u] = mask == 0 ? 1: 0; // if all the nodes visited, then mask will be 0, so one path.
        }

        if (dp[mask][u] != -1) {
            return dp[mask][u];
        }
        ll ans = 0;

        for (int &v: adj[u]) {
            if ((mask & (1 << v))) { 
                // the node is not visited.
                ans = (ans + dfs(mask, v) % mod) % mod;
            }
        }

        return dp[mask][u] = ans % mod;
    };

    // 1 -> not visited, 0 -> visited
    cout << dfs((1 << n) - 1, 0); // first all the vertices should be unvisited
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