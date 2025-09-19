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

vector<vector<int>> edges;
int n, m;

class DSU {
public:
    vector<int> parent, height;
    DSU(int n) {
        parent.resize(n + 1), height.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return parent[x];
        }
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        int parent_x = find(x), parent_y = find(y);
        
        if (height[parent_x] < height[parent_y]) {
            swap(parent_x, parent_y);
        }
        parent[parent_y] = parent_x;
        height[parent_x] = max(height[parent_x], height[parent_y] + 1);
    }

    bool is_connected(int x, int y) {
        return find(x) == find(y);
    }
};


void solve() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    
    sort(range(edges));

    DSU dsu(n);
    ll ans = 0;
    int edge_num = 0;

    vector<vector<int>> adj(n + 1);

    for (auto e: edges) {
        int w = e[0], u = e[1], v = e[2];
        if (!dsu.is_connected(u, v)) {
            ans += w;
            dsu.merge(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            edge_num++;
        }
        if (edge_num == n - 1) {
            break;
        }
    }

    vector<bool> vis(n + 1, false);

    std::function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (int &v: adj[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        } 
    };

    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    cout << ans << "\n";
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