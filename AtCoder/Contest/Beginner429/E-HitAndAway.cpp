#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    string s = "#";
    {
        string temp;
        cin >> temp;
        s += temp;
    }

    queue<pair<pair<int, int>, int>> q;

    vector<vector<int>> vis(n + 1, vector<int> (2, -1));
    vector<vector<int>> dist(n + 1, vector<int> (2, -1));

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'S') {
            q.push({{i, i}, 0});
            vis[i][0] = i;
            dist[i][0] = 0;
        }
    }
    debug(q);

    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        int u = x.first.first, v = x.first.second;
        int d = x.second;

        for (int node: adj[v]) {
            if (vis[node][0] == -1) {
                // first time visiting
                vis[node][0] = u;
                dist[node][0] = d + 1;
                q.push({{u, node}, d + 1});
            } else if (vis[node][1] == -1 && vis[node][0] != u) {
                vis[node][1] = u;
                dist[node][1] = d + 1;
                q.push({{u, node}, d + 1});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'D') {
            cout << dist[i][1] + dist[i][0] << "\n";
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