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

vector<vector<int>> dp;
vector<int> len;
vector<bool> vis;

void dfs(int u) {
    vis[u] = true;
    if (!vis[dp[u][0]]) {
        dfs(dp[u][0]);
    }
    len[u] = len[dp[u][0]] + 1; 
}

int lift(int x, int dist) {
    if (dist <= 0) {
        return x;
    }
    int i = 0;
    while (dist) {
        int bit = (dist % 2);
        if (bit) {
            if (dp[x][i] != -1) {
                x = dp[x][i];
            }
        }
        dist = dist >> 1;
        i++;
    }
    return x;
}

void solve() {
    
    int n, q;
    cin >> n >> q;

    dp.resize(n + 1, vector<int> (31, -1));
    len.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> dp[i][0];
    }       

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    for (int j = 1; j <= 30; j++) {
        for (int i = 1; i <= n; i++) {
            if (dp[i][j - 1] != -1) {
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << i << "->" << len[i] << "\n";
    // }

    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        int c = lift(a, len[a]);
        // cout << c << "\n";
        // first we'll check if the a and b are in same branch of the graph
        if (lift(a, len[a] - len[b]) == b) {
            cout << len[a] - len[b] << "\n";
        }
        // Then maybe they for a cycle, so first we'll find the initial vertex and from there we'll try to reach b 
        else if (lift(c, len[c] - len[b]) == b) {
            cout << len[a] + len[c] - len[b] << "\n";
        } else {
            cout << -1 << "\n";
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