#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m;
void solve() {
    cin >> n >> m;
    vector<int> adj[n + 1];
    
    for (int i = 0, from, to; i < m; i++) {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);

    }

    queue<pair<int, int>> q;
    q.push({1, 1});
    vector<bool> vis(n + 1, false);
    vector<int> path(n + 1, -1);
    vis[1] = true;

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int v: adj[u.second]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push({u.first + 1, v});
                path[v] = u.second;
                if (v == n) {
                    cout << u.first + 1 << "\n";
                    vector<int> shortestPath;
                    for (int i = v; i != -1; i = path[i]) {
                        shortestPath.push_back(i);
                    }
                    reverse(shortestPath.begin(), shortestPath.end());

                    for (int x: shortestPath) {
                        cout << x << " ";
                    }
                    cout << "\n";
                    return;
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
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