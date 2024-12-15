#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

void solve() {
    int n;
    cin >> n;
    set<int> adj[n + 1];

    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        adj[i].insert(x);
        adj[x].insert(i);
    }
    
    int mx = 0;
    vector<bool> vis(n + 1, 0);
    std::function<void(int)> dfs = [&](int idx)  {
        vis[idx] = 1;

        for (auto node : adj[idx]) {
            if (!vis[node]) {
                dfs(node);
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            mx++;
            dfs(i);
        }
    }

    int num_cycles = 0;
    vis = vector<bool> (n + 1, 0);

  
    std::function<bool(int)> bfs = [&] (int idx) {
        queue<pair<int, int>> q;
        q.push({idx, -1});
        vis[idx] = true;

        int is_cycle = false;
        while (!q.empty()) {
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();
            // cout << "curr : " << curr << " -> ";
            for (auto x : adj[curr]) {
                if (!vis[x]) {
                    vis[x] = 1;
                    q.push({x, curr});
                }
                else if (x != parent) {
                    // cout << "x : " << x << '\n';
                    return true;
                }
            }
        }

        return false;
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            // debug("i", i);
            num_cycles += bfs(i);
        }
    }
    cout << ((mx == num_cycles)? mx : num_cycles + 1) << " " << mx << '\n';
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