#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, ll>> adj[n + 1];

    vector<vector<ll>> dp(n + 1, vector<ll> (n + 1, LLONG_MAX));
    while (m--) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
        // update the distance, the distances can be repeated, so take minimum.
        dp[a][b] = min(w, dp[a][b]);
        dp[b][a] = min(w, dp[b][a]);
    }



    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                // from i -> i, the distance will be zero
                dp[i][j] = 0;
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k) {
                continue;
            }
            for (int j = 1; j <= n; j++) {
                if (j == k || (dp[i][k] == LLONG_MAX || dp[k][j] == LLONG_MAX)) {
                    continue;
                }
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dp[a][b] == LLONG_MAX) {
            cout << -1 << "\n";
        } else {
            cout << dp[a][b] << "\n";
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