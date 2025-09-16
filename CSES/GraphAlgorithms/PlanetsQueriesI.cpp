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

void solve() {
    int n, q;
    cin >> n >> q;
    // vector<int> adj[n + 1];  ** <- TLE Reason
    int k = 30;
    vector<vector<int>> dp(n + 1, vector<int> (k, -1));

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> dp[i][0];
        // adj[i].push_back(x); **  <- TLE Reason (due to push_back)
    }

    for (int j = 1; j < k; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        int u, dist;
        cin >> u >> dist;
        int ans = u;

        for (int i = 0; i < 30; i++) {
            if ((dist & (1LL << i))) {
                ans = dp[ans][i];
            }
        }
        cout << ans << "\n";
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