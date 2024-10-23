#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m;

bool bfs(set<int> adj[], vector<bool> &vis, int src) {
    queue<int> q;
    q.push(src);
    vis[src] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(auto neigbour: adj[x]) {
            if(!vis[neigbour]) {
                vis[neigbour] = 1;
                q.push(neigbour);
            }
        }
    }
}

bool isFullyConnected(set<int> adj[]) {
    int components = 0;
    vector<bool> vis(n, 0);

    for(int i = 0; i < n; i++) {
        if(*adj[i].begin() == -1) {
            continue;
        }
        else {
            if(!vis[i]) {
                components++;
                vis[i] = 1;
                bfs(adj, vis, i);
            }
        }
    }
    return components == 1;
}

void solve() {
    cin >> n >> m;
    set<int> adj[n];

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[--a].insert(--b);
        adj[b].insert(a);
    }    

    int close[n] = {0};
    for(int i = 0; i < n; i++) {
        cin >> close[i]; 
        close[i]--;
    }

    if(isFullyConnected(adj)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    for(int i = 0; i < n - 1; i++) {
        for(auto neighbour: adj[close[i]]) {
            adj[neighbour].erase(adj[neighbour].find(close[i]));
        }
        adj[close[i]].clear();
        adj[close[i]].insert(-1);

        if(isFullyConnected(adj)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

int main() {
    NFS
    string file = "closing";
    freopen((file + ".in").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);

    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}