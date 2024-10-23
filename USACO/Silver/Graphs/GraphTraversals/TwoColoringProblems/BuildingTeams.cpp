#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m;


void bfs(vector<int> adj[], int src, vector<int> &ans, vector<bool> &vis) {
    ans[src] = 1;
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int x = q.front();
        q.pop();    
        vis[x] = 1;

        for(auto node: adj[x]) {
            if(!vis[node]) {
                if(ans[x] == 1) {
                    ans[node] = 2;
                }
                else {
                    ans[node] = 1;
                }
                q.push(node);
            }
        }
    }
}

bool isBipartite(vector<int> adj[], vector<int> &ans) {
    vector<bool> vis(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int x = q.front();
                q.pop();
                vis[x] = 1;

                int c1 = ans[x];
                for(auto nei: adj[x]) {
                    if(!vis[nei]) {
                        q.push(nei);
                    }

                    if(c1 == ans[nei]) {
                        return false;
                    }
                }
            }
        }

    }
    return true;
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

    vector<int> ans(n + 1, 0);
    vector<bool> vis(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            bfs(adj, i, ans, vis);
        }
    }    

    if(!isBipartite(adj, ans)) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    #endif

    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}