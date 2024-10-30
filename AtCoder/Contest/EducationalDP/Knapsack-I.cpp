#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, totWeight;
vector<ll> v, w;
ll dp[101][(int)(1e5 + 1000)];

ll f(int idx, ll weight = 0) {
    if(idx == n) {
        return 0;
    }

    if(dp[idx][weight] != -1) {
        return dp[idx][weight];
    }
    
    ll pick = 0, notPick = f(idx + 1, weight);
    if(weight + w[idx] <= totWeight) {
        pick += v[idx] + f(idx + 1, weight + w[idx]);
    }

    return dp[idx][weight] = max(pick, notPick);
}
void solve() {
    cin >> n >> totWeight;
    v.resize(n), w.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }    
    memset(dp, -1, sizeof(dp));

    cout << f(0) << "\n";
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