#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;

void dfs(int start, set<int> adj[], vector<bool> &vis) {
    vis[start] = 1;

    for(auto node: adj[start]) {
        if(!vis[node]) {
            dfs(node, adj, vis);
        }
    }
}
int numberOfConnectedComponents(set<int> adj[]) {
    int ans = 0;
    vector<bool> vis(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            ans++;
            dfs(i, adj, vis);
        }
    }    
    return ans;
}


bool isCycle(set<int> adj[], int start, vector<bool> &vis) {
    queue<pair<int, int>> q;
    q.push({start, -1});
    vis[start] = 1;

    bool iscycle = false;
    while(!q.empty()) {
        int curr = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto neighbour: adj[curr]) {
            if(!vis[neighbour]) {
                vis[neighbour] = 1;
                q.push({neighbour, curr});
            }
            else if(neighbour != parent) {
                iscycle = 1;
            }
        }
    }
    return iscycle;
}

void solve() {
    cin >> n;
    set<int> adj[n + 1];
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        adj[i].insert(x);
        adj[x].insert(i);
    }

    int mx = numberOfConnectedComponents(adj);

    int nonCyclicComponents = 0;
    vector<bool> vis(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        if(!vis[i] && !isCycle(adj, i, vis)) {
            nonCyclicComponents++;
        }
    }
    // debug("non", nonCyclicComponents);
    cout << mx - (nonCyclicComponents - (bool)nonCyclicComponents) << " "<< mx << "\n";
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
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}