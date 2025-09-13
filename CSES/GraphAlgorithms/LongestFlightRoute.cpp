#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T, typename Container = vector<T>, typename Compare = less<T>>
using heap = priority_queue<T, Container, Compare>;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

// First idea was to solve using Djikstra, but due to complexity, it will give TLE
// As it was DAG, so I thought of using dp. But the problem was to construct the path
// I tried following methods before success:
// 1. Used path array to store the parent of each node, didn't work, as it will not track all the paths.
// 2. Then I thougt of aggregating the path from the n, so each dp[i] will store array,
// where first element is the distance from n, and the rest of element is the vertex, it gave runtime error.
// I think too many nodes, so possibly Memory Limit.
// 3. Then I thought of storing the parent in each dp state. dp[i] -> {dist, parent}. It gave wrong answer, as while visiting node
// that has been already visited, it will give wrong information,
/**
 * Ex,:
    10 10
    2 6
    1 2
    4 6
    5 6
    2 5
    7 8
    6 10
    1 10
    3 5
    4 9
 */
// 4. Then finally for each vertext i, dp[i] will store the distance from n and the next vertex, and this was correct and it 
// worked.

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> path(n + 1, -1);
    vector<vector<ll>> dp(n + 1);

    std::function<vector<ll>(int, int)> f = [&](int u, int parent) -> vector<ll> {
        if (u == n) {
            return dp[u] = {1, -1};
        }
        if (!dp[u].empty()) {
            return dp[u];
        }
        vector<ll> ans = {INT_MIN, -1};

        for (int &v: adj[u]) {
            vector<ll> x = f(v, u);
          
            if (x[0] == INT_MIN) {
                continue;
            }

            if (x[0] + 1 > ans[0]) {
                ans[0] = x[0] + 1;
                ans[1] = v;
            }
        }

        return dp[u] = ans;
    };
    
    vector<ll> ans = f(1, -1);
    if (ans[0] == INT_MIN) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << ans[0] << "\n";

    for (int i = 1; i != -1; i = dp[i][1]) {
        cout << i << " ";
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