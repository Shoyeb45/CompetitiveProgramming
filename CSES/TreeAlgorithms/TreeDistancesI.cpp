#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<vector<int>> adj;
vector<int> dista[2];
int mxDist = 0, farthestNode = 0;

/// @brief Function to perform DFS
/// @param start   Node from dfs will start
/// @param x       0 or 1, it's the index for dista array, 0 means dist(a, i) and 1 means disa(b, i), a and b are the nodes of diameter
/// @param dist    Depth
/// @param prev    Parent node for start node
void dfs(int start, int x, int dist = 0, int prev = -1) {
    if(mxDist < dist) {
        farthestNode = start, mxDist = dist;
    }
    dista[x][start] = dist;

    for(auto node: adj[start]) {
        if(node != prev) {
            dfs(node, x, dist + 1, start);
        }
    }
}

void solve() {
    cin >> n;
    adj.resize(n + 1);
    for(int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dista[0].resize(n + 1, 0), dista[1].resize(n + 1, 0);

    // Find farthest node from 1, let that node is a
    dfs(1, 0);

    mxDist = 0;
    // Find farthest node from a, let that node b. Also calculating the distance of all nodes from a
    dfs(farthestNode, 0);
  
    mxDist = 0;
    // Distance of all nodes from b
    dfs(farthestNode, 1);

    // Then for node i, the maximum distance will be max(dist(a, i), dist(b, i)).
    for(int i = 1; i <= n; i++) {
        cout << max(dista[0][i], dista[1][i]) << " \n"[i == n];
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