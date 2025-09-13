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


void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, ll>> adj[n + 1];
    
    while (m--) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<ll> dist(n + 1, LLONG_MAX), ways(n + 1, 0);
    vector<int> min_nodes(n + 1, 0), max_nodes(n + 1, 0);
    min_heap<pair<ll, int>> pq;
    pq.push({0, 1});
    dist[1] = 0, ways[1] = 1;

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        ll d = p.first;
        int u = p.second;

        if (dist[u] < d) {
            continue;
        }

        for (auto x: adj[u]) {
            int v = x.first;
            ll w = x.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                ways[v] = (ways[u]) % mod;
                min_nodes[v] = min_nodes[u] + 1;
                max_nodes[v] = max_nodes[u] + 1;
                pq.push({dist[v], v});
            } else if (dist[u] + w == dist[v]) {
                ways[v] = (ways[v] + ways[u]) % mod;
                min_nodes[v] = min(min_nodes[u] + 1, min_nodes[v]);
                max_nodes[v] = max(max_nodes[v], max_nodes[u] + 1);
            }
        }
    }
    cout << dist[n] << " " << ways[n] << " " << min_nodes[n] << " " << max_nodes[n] << "\n";
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