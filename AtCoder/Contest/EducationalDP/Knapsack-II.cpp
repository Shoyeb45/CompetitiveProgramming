#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

ll n, totWeight;
vector<ll> v, w;
unordered_map<ll, ll> dp[101];



void solve() {
    cin >> n >> totWeight;
    v.resize(n), w.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }    

    int sum_v = 0;
    for (auto x: v) {
        sum_v += x;
    }

    vector<vector<ll>> dp(n, vector<ll>(sum_v + 1, INT_MAX));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= sum_v; j++) {
            if (i == 0) {
                if (j == 0) {
                    dp[i][j] = 0;
                } else if (j == v[0]) {
                    dp[i][j] = w[0];
                }
            } else {
                ll not_taken = INT_MAX, taken = INT_MAX;
                not_taken = dp[i - 1][j];
                if (j >= v[i] && dp[i - 1][j - v[i]] != INT_MAX) {
                    taken = dp[i - 1][j - v[i]] + w[i];
                }
                dp[i][j] = min(not_taken, taken);
            }
        }
    }

    ll ans = INT_MIN;

    for (int i = 0; i < n; i++) {
        for (ll j = 0; j < sum_v + 1; j++) {
            if (dp[i][j] <= totWeight) {
                ans = max(ans, j);
            }
        }
    }
    cout << ans << "\n";
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