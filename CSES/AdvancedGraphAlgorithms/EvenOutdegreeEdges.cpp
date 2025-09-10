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
vector<pair<int, int>> ans;
vector<int> is_odd;
vector<int> vis;
int timer = 1;

void dfs(int u, int parent = -1) {
    vis[u] = timer++;

    for (int v: adj[u]) {
        if (v != parent) {
            if (!vis[v]) {
                dfs(v, u);

                if (is_odd[v]) {
                    // v has odd outdegree edges, so add one and make it even
                    ans.push_back({v, u});
                    is_odd[v] = 0;
                } else {
                    // we can add one outdegree edge to the v, and update the is_odd
                    ans.push_back({u, v});
                    is_odd[u] ^= 1;
                }
            } else if (vis[u] > vis[v]) {
                // backward edge
                ans.push_back({u, v});
                is_odd[u] ^=1;  // one edge from the u
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    is_odd.resize(n + 1, 0);
    vis.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }

    }

    if (accumulate(is_odd.begin(), is_odd.end(), 0)) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (auto it: ans) {
            cout << it.first << " " << it.second << "\n";
        }
    }
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