#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m;
void dfs(int start, int x, vector<int> adj[][2], vector<bool> &vis) {
    vis[start] = 1;

    for(auto node: adj[start][x]) {
        if(!vis[node]) {
            dfs(node, x, adj, vis);
        }
    }
}
void solve() {
    cin >> n >> m;

    vector<int> adj[n + 1][2];
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }

    vector<bool> vis(n + 1, 0);
    dfs(1, 0, adj, vis);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cout << "NO\n" << 1 << " " << i << "\n";
            return;
        }
    }

    fill(range(vis), 0);
    dfs(1, 1, adj, vis);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cout << "NO\n" << i << " " << 1 << "\n";
            return;
        }
    }

    cout << "YES\n";
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