#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, m;

void dfs(int src, vector<int> adj[], vector<bool> &vis) {
    vis[src] = 1;

    for(auto node: adj[src]) {
        if(!vis[node]) {
            dfs(node, adj, vis);
        }
    }
}
void solve() {
    cin >> n >> m;
    vector<int> adj[n + 1];

    
    while(m--) {
        int a, d, k;
        cin >> a >> d >> k;
        int prev = a;
        for(int i = a + d; i <= a + d * k; i += d) {
            adj[prev].push_back(i);
            adj[i].push_back(prev);
            prev = i;
        }
    }

    vector<bool> vis(n + 1, 0);

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            ans++;
            dfs(i, adj, vis);
        }
    }
    cout << ans << "\n";
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}