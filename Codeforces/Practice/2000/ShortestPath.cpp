#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m, k;

void solve() {
    cin >> n >> m >> k;
    
    vector<int> adj[n + 1];
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    set<pair<pair<int, int>, int>> bad;
    for (int i = 0, a, b, c; i < k; i++) {
        cin >> a >> b >> c;
        bad.insert(make_pair(make_pair(a, b), c));
    }

    map<pair<int, int>, pair<int, int>> parent;

    set<pair<int, int>> vis;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {-1, 1}});

    parent[{-1, 1}] = {-2, -2};

    while (!q.empty()) {
        pair<int, int> u = q.front().second;
        int dist = q.front().first;
        if (u.second == n) {
            cout << dist << "\n";
            vector<int> ans;
            
            while (u.first != -2) {
                ans.push_back(u.second);
                u = parent[u];
            }
            reverse(range(ans));

            for (int x: ans) {
                cout << x << " ";
            }
            cout << "\n";
            return;
        }
        q.pop();

        for (int w: adj[u.second]) {
            auto triplet = make_pair(u, w);
            if (bad.find(triplet) == bad.end() && vis.find(make_pair(u.second, w)) == vis.end()) {
                q.push({dist + 1, {u.second, w}});
                vis.insert({u.second, w});
                parent[{u.second, w}] = u;
            }   
        }
    }

    cout << -1 << "\n";
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