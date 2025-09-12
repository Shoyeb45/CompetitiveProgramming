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
    Edge(int u, int v, ll w) {
        this->u = u, this->v = v, this->w = w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, ll>> adj[n + 1];
    vector<Edge> edges;
    while (m--) {
        int a, b; 
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back({a, w});
        edges.push_back(Edge(a, b, w));
    }
   

    vector<ll> dist(n + 1, 3);
    dist[1] = 0;

    bool is_cycle = false;
    vector<int> parent(n + 1, -1);
    // Bellman Ford to update the distance 
    for (int i = 0; i < n; i++) {
        for (Edge &e: edges) {
            int u = e.u, v = e.v;
            ll w = e.w;

            dist[v] = min(dist[v], dist[u] + w);
        }
    }


    // use Bellman again to find the cycle, update the parent
    for (int i = 0; i < n; i++) {
        for (Edge &e: edges) {
            int u = e.u, v = e.v;
            ll w = e.w;

            ll init_dist = dist[v];
            dist[v] = min(dist[v], dist[u] + w);
            if (dist[v] != init_dist) {
                is_cycle = true;
                parent[v] = u;
            }
        }
    }
    



    if (is_cycle) {
        int node = -1;
        for (int i = 1; i <= n; i++) {
            if (parent[i] != -1) {
                node = i; // node is the vertex which is in the cycle.
                break;
            }
        }

        vector<int> cycles;
        set<int> st;
        // push all the ndes into cycles.
        while (st.find(node) == st.end()) {
            cycles.push_back(node);
            st.insert(node);
            node = parent[node];
        }
        cycles.push_back(node);
        reverse(range(cycles));
        cout << "YES\n";
        unordered_map<int, int> mp;
        // print the answer
        for (int &i: cycles) {
            cout << i << " ";
            if (mp.find(i) != mp.end()) {
                break;
            }
            mp[i]++;
        }
        return;
    }
    cout << "NO\n";
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