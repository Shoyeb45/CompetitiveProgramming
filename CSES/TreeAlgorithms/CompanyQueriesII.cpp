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

int n, q;
vector<vector<int>> adj, dp; 
vector<int> depth;

void dfs(int u, int parent = -1, int _depth = 0) {
    for (int &v: adj[u]) {
        if (parent != u) {
            dfs(v, u, _depth + 1);
        }
    }
    depth[u] = _depth;
}

int lca(int u, int v) {
    // keep always depth[v] > depth[u]
    if (depth[u] > depth[v]) {
        swap(u, v);
    }
    int diff = depth[v] - depth[u];

    int power = 0;
    // int node = v;
    while (diff) {
        int bit = diff % 2;
        if (bit) {
            if (dp[v][power] == -1) {
                break;
            }
            v = dp[v][power];
        }
        if (v == -1) {
            break;
        }
        power++, diff /= 2;
    }
    
    if (v == u) {
        return v;
    }
    for (int i = (int) log2(n) + 1; i >= 0; i--) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i], v = dp[v][i];
        }
    }
    return dp[u][0];
}
void solve() {
    cin >> n >> q;
    dp.resize(n + 1, vector<int> ((int) log2(n) + 2, -1));
    adj.resize(n + 1);
    depth.resize(n + 1, 0);
    
    for (int v = 2; v <= n; v++) {
        int u;
        cin >> u;
        adj[u].push_back(v);
        dp[v][0] = u;
        // dp[v][0] = u;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= (int) log2(n) + 1; j++) {
            
            if (dp[i][j - 1] != -1) {
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }

  
    dfs(1);

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
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