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
vector<ll> numOfNodes, ans;

void dfs(int start, int prev = -1, ll dist = 0) {
    ans[1] += dist;
    numOfNodes[start] = 1;
    for(int node: adj[start]) {
        if(node != prev) {
            dfs(node, start, dist + 1);
            numOfNodes[start] += numOfNodes[node];
        }
    }
}


void dfs2(int start, int prev = -1) {
    for(int node: adj[start]) {
        if(node != prev) {
            ans[node] = ans[start] + n - 2 * numOfNodes[node];
            dfs2(node, start); 
        }
    }
}

void solve() {
    cin >> n;
    adj.resize(n + 1); ans.resize(n + 1, 0), numOfNodes.resize(n + 1, 0);
    for(int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    dfs2(1);

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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