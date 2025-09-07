#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, idx = 0, dfs_timer = 1;
vector<set<int>> adj;
vector<int> in, out, leaves, ans;

void _dfs(int u, int parent = -1) {
    in[u] = dfs_timer++;
    for (int v: adj[u]) {
        if (v != parent) {
            _dfs(v, u); 
        } 
    }
    out[u] = dfs_timer++;
}

bool is_in_subtree(int u, int v) {
    return in[u] < in[v] && out[v] < out[u];
}

void dfs(int u, int parent = -1) {
    // order of the leaves matched, so return;
    if (idx >= leaves.size()) {
        return;
    }
    // increment the index if we found the leaf
    if (u == leaves[idx]) {
        idx++;
    }

    vector<int> children(adj[u].begin(), adj[u].end());
    for (int i = 0; i < children.size(); i++) {
        int v = children[i];
        // either go to that subtree where our leaf is or go to the leaf
        if ((v != parent && idx < leaves.size() && is_in_subtree(v, leaves[idx])) || v == leaves[idx]) {
            ans.push_back(u);
            dfs(v, u);
            // since we have removed the edges, so update the children
            children = vector<int> (adj[u].begin(), adj[u].end());
            i = -1;
        }
    }

    ans.push_back(u);  // for tracking the path

    if (parent != -1) {
        adj[u].erase(parent);
        adj[parent].erase(u);
    } 

}
void solve() {
    cin >> n;
    adj.resize(n + 1);

    in.resize(n + 1), out.resize(n + 1);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    int k;
    while (cin >> k) {
        leaves.push_back(k);
    }
    // precompute in and out
    _dfs(1);
    dfs(1);

    if (idx != leaves.size()) { // we never reached the end, means we weren't able to travel the leaves in given order
        cout << -1 << "\n";
        return;
    } 
    for (auto x: ans) {
        cout << x << " ";
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