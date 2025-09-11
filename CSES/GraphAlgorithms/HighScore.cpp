#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

class Edge {
public:
    int u, v;
    ll w;
    Edge(int a, int b, ll w) {
        u = a, v = b, this -> w = w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1), adj_t(n + 1);
    vector<Edge> edges;

    while (m--) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        edges.push_back(Edge(a, b, w));
        adj[a].push_back(b);
        adj_t[b].push_back(a);
    }     

    vector<ll> dist(n + 1, -1e18);
    dist[1] = 0;

    // Bellman Ford, but finding the maximum distance
    for (int i = 0; i < n - 1; i++) {
        for (auto &e: edges) {
            if (dist[e.u] != -1e18 && dist[e.u] + e.w > dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            } 
        }
    }

    // we need to check if there is positive cycle c, such that we can reach from 1...c
    // and c..n
    // from_1[i] -> if ith vertex is reachable from 1 
    // from_n[i] -> if ith vertex is reachable from n 

    vector<bool> from_1(n + 1, false), from_n(n + 1, false);
    std::function<void(int, vector<bool>&)> dfs = [&](int u, vector<bool> &vis) -> void {
        vis[u] = true;
        for (int v: adj[u]) {
            if (!vis[v]) {
                dfs(v, vis);
            }
        }
    };

    dfs(1, from_1);
    // for checking the if the vertex is reachable from n, we need transponse graph of given.
    adj = adj_t;
    dfs(n, from_n);

    for (auto &e: edges) { 
        // If we find the cycle which is increasing.
        if (dist[e.u] != -1e18 && dist[e.u] + e.w > dist[e.v]) {
            // check the reachability.
            if (from_1[e.v] && from_n[e.v]) {
                cout << -1 << "\n";
                return;
            }
        } 
    }

    cout << dist[n] << "\n";
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

    while (tt--) {
        solve();
    }

    return 0;
}