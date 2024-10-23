#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


void dfs(int start, vector<vector<bool>> &adj, vector<bool> &vis, int n) {
    vis[start] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[start][i] && !vis[i]) {
            dfs(i, adj, vis, n);
        }
    }
}
void solve(int n, int m) {
    vector<vector<bool>> adj(n, vector<bool> (n, 0));

    vector<pair<int, int>> edges;
    for(int i = 0, a = 0, b = 0; i < m; i++) {
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
        edges.push_back({a, b});
    }

    for(auto edge: edges) {
        adj[edge.first][edge.second] = 0;
        adj[edge.second][edge.first] = 0;
        vector<bool> vis(n, 0);
        dfs(0, adj, vis, n);

        for(auto x: vis) {
            if(!x) {
                cout << "YES\n";
                return;
            }
        }

        adj[edge.first][edge.second] = 1;
        adj[edge.second][edge.first] = 1;
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

    int n = 0, m = 0;
    while (true) {
        cin >> n >> m;
        if(n == m && n == 0) {
            break;
        }
        solve(n, m);
    }

    return 0;
}