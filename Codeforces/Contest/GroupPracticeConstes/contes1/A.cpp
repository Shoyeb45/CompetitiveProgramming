#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, m;
vector<pair<int, int>> c;
void bfs(vector<int> adj[], vector<bool> &visited, int start) {
    queue<int> q;
    q.push(start);
    
    while(!q.empty()) {
        int curr = q.front();
        visited[curr] = true;
        q.pop();

        for(auto node: adj[curr]) {
            if(!visited[node]) {
                q.push(node);
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    c.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i].first;
        c[i].second = i + 1;
    }

    vector<bool> visited(n + 1, false);
    vector<int> adj[n + 1];

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    sort(range(c));

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[c[i].second]) {
            ans += c[i].first;
            bfs(adj, visited, c[i].second);
        }
    }
    cout << ans << "\n";
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
