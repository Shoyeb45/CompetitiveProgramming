#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, m;

void bfs(vector<int> adj[], vector<int> &vis, int src, int x) {
    queue<int> q;
    q.push(src);
    while(!q.empty()) {
        int curr = q.front();
        vis[curr] = x;
        q.pop();

        for(auto node: adj[curr]) {
            if(vis[node] == 0) {
                q.push(node);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    vector<int> adj[n + 1];

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int x = 0;
    vector<int> vis(n + 1, 0);
    vector<int> edges;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            edges.push_back(i);
            x++;
            bfs(adj, vis, i, x);
        }
    }

    cout << x - 1 << "\n";
    
    for(int i = 0; i < edges.size() - 1; i++) {
        cout << edges[i] << " " << edges[i + 1] << "\n";
    }
    

    cout << '\n';
}

int main() {
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
