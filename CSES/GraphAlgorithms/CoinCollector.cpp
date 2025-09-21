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
const int MAX_N = (int) 1e5 + 1;


// My initial idea was to compute and memoize the cost from each path, then for each node, the maximum cost will be
// for vertex u -> for v belongs adj[u] max(cost(v)) + original_cost[u], here cost is the cost for that vertex, like in the dfs tree.

// But this idea won't work, as we can't do this in cyclic graph, we need dag.

// Correct Idea: Convert the given graph to DAG, how?
// Divide the graph into SCC, now consider the one scc as a node and then make a graph
// The resultant graph will be DAG
// then apply the same idea using dp

ll cost[MAX_N]; // cost of original vertices
vector<int> adj[MAX_N]; // original graph
vector<int> adj_t[MAX_N]; // transpose of original graph
bool vis[MAX_N]; // visited for dfs
int compo[MAX_N]; // compo[i] -> scc of vertex i in original graph
set<int> dag[MAX_N]; // new graph, i.e., DAG
vector<ll> dag_cost; // summation of all the nodes in that scc of the vertex
stack<int> order; // for topological sorting

int n, m;

void dfs_1(int u) {
    vis[u] = 1;
    for (int &v: adj[u]) {
        if (!vis[v]) {
            dfs_1(v);
        }
    }
    order.push(u);
}

ll sum = 0;

void dfs_2(int u, int scc) {
    sum += cost[u];
    compo[u] = scc;
    vis[u] = 1;
    for (int &v: adj_t[u]) {
        if (!vis[v]) {
            dfs_2(v, scc);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj_t[v].push_back(u);
    }

    // find topo sort
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs_1(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        vis[i] = false;
    }

    int scc = 0;
    dag_cost.push_back(-1);
    // find scc
    while (!order.empty()) {
        int x = order.top();
        order.pop();

        if (!vis[x]) {
            dfs_2(x, ++scc);
            // insert the sum of all the cost of that scc
            dag_cost.push_back(sum);
            sum = 0;
        }
    }

    
    // construct the DAG from the given graph
    for (int i = 1; i <= n; i++) {
        for (int &v: adj[i]) {
            if (compo[i] != compo[v]) {
                dag[compo[i]].insert(compo[v]);
            }
        }
    }
    
    vector<ll> dp(scc + 1, -1);

    std::function<ll(int)> dfs = [&](int u) {
        if (dp[u] != -1) {
            return dp[u];
        }

        ll ans = 0;
        for (int v: dag[u]) {
            ll temp = dfs(v);
            ans = max(temp, ans);
        }
        return dp[u] = ans + dag_cost[u];
    };

    ll ans = 0;
    // find for all new scc vertices
    for (int i = 1; i <= scc; i++) {
        if (dp[i] == -1) {
            ans = max((ll)ans, dfs(i));
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