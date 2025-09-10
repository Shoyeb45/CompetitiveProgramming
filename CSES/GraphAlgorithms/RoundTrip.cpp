#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m;
vector<vector<int>> adj;
vector<int> ans;
vector<bool> vis;

bool dfs(int u, int parent = -1) {
    vis[u] = true;
    // store the path
    ans.push_back(u);

    bool temp = false;
    for (int v: adj[u]) {
        if (!vis[v]) {
            temp |= dfs(v, u);
            // if we found the cycle then return
            if (temp) {
                return true;
            }
        } else if (v != parent) {
            // we found backedge
            ans.push_back(v);
            return true;
        }
    }
    ans.pop_back(); // this is for removing the wrong path
    // see example:
    // 4 4
    // 1 2
    // 1 3
    // 3 4
    // 4 1
    return false;
}
void solve() {
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1, false);

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }    

    bool ok = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ok |= dfs(i);
            if (ok) {
                break;
            }
        }
        ans.clear();
    }

    if (!ok) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    int idx = -1; // index for tracking the last value in the ans, that is the start and end city.
    
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == ans.back()) {
            idx = i;
            break;
        }
    }
    cout << (int) ans.size() - idx << "\n";

    for (int i = idx; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
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