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

// Idea is to do dfs and find the backedge and process the cycle.
// We need some info is we are visisting some node, then for that path, we need to make it true.
// If we didn't find the cycle then returning we'll make that info false, specifying that 
// we are not taking that node in current path and in that way we can check for v, if that
// is in cycle or not.

int n, m;
vector<vector<int>> adj;
vector<bool> vis, path_visited;
vector<int> ans;

bool dfs(int u, int parent = -1) {
    ans.push_back(u);

    vis[u] = true;
    path_visited[u] = true;
    for (int &v: adj[u]) {
        if (!vis[v]) {
            if (dfs(v, u)) {
                return true;;
            }
            
        } else if (path_visited[v]) {
            // backedge, cycle found
            ans.push_back(v);
            return true;
        }
    }
    path_visited[u] = false;
    ans.pop_back();
    return false;
} 

void solve() {
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1, false);
    path_visited.resize(n + 1, false);

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }    

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i)) {
                break;
            }
            ans.clear();
        }
    }    

    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < (int) ans.size(); i++) {
        mp[ans[i]].push_back(i);
    }
 
    for (auto it: mp) {
        
        if (it.second.size() >= 2) {
            int l = it.second[0], r = it.second[1];
            cout << r - l + 1 << "\n";
            for (int i = l; i <= r; i++) {
                cout << ans[i] << " \n"[i == r];
            } 
            return;
        }   
    }
    cout << "IMPOSSIBLE\n";
    cout << "\n";
    
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