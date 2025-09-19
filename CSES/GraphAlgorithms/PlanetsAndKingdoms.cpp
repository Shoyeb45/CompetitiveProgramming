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

// straght forward scc, use Kosaraju or Tarjan's Algo
int n, m;
void solve() {
    cin >> n >> m;
    vector<int> adj[n + 1], adj_t[n + 1];

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj_t[v].push_back(u);
    }    

    stack<int> st;
    vector<bool> vis(n + 1, false);

    std::function<void(int)> dfs_1 = [&](int u) {
        vis[u] = true;
        
        for (int &v: adj[u]) {
            if (!vis[v]) {
                dfs_1(v);
            }
        }
        st.push(u);
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs_1(i);
        }
    }
    fill(range(vis), false);

    vector<int> path;

    std::function<void(int)> dfs_2 = [&](int u) {
        vis[u] = true;
        path.push_back(u);
        for (int &v: adj_t[u]) {
            if (!vis[v]) {
                dfs_2(v);
            }
        }
    };

    int scc = 0;

    vector<int> ans(n + 1);

    while (!st.empty()) {
        int i = st.top();
        st.pop();
        if (!vis[i]) {
            dfs_2(i);
            scc++;
            for (int &node: path) {
                ans[node] = scc;
            }
            path.clear();
        }
    }

    cout << scc << "\n";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n]; 
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