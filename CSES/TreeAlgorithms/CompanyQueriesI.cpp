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

// This question can be easily solved by Binary Lifting.
// See link: https://github.com/Shoyeb45/DataStructureAndAlgorithm/tree/main/Algorithms/Graph/LCA

int n, q;
void solve() {
    cin >> n >> q;
    vector<int> adj[n + 1];
    vector<vector<int>> dp(n + 1, vector<int> (31, -1));
    
    for (int i = 2, v; i <= n; i++) {
        cin >> v;
        adj[i].push_back(v);
        adj[v].push_back(i);
        dp[i][0] = v;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 30; j++) {
            if (dp[i][j - 1] != -1) {
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
            }
        }
    }


    auto query = [&](int x, int k) -> int {
        int ans = x;
        for (int i = 0; i <= 30; i++) {
            int bit = ((1 << i) & k);
            if (bit) {
                ans = dp[ans][i];
            }
            if (ans == -1) {
                break;
            }
        }
        return ans;
    };

    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << query(x, k) << "\n";
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