#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll dp[102];
int n;
vector<int> a;

ll f(int idx) {
    if(idx >= n) {
        return INT_MIN;
    }

    if(idx == n - 1) {
        return a[idx];
    }

    if(dp[idx] != -1) {
        return dp[idx];
    }

    // ll ans = max((ll)(idx >= 0? a[idx]: 0) + f(idx + 1), (ll)(idx >= 0? a[idx]: 0) + f(idx + 2));

    // if(idx >= 0) {
    //     dp[idx] = ans;
    // }

    ll ans = max(
        a[idx] + f(idx + 1),
        a[idx] + f(idx + 2)
    );

    return dp[idx] = ans;

}

void solve() {
    cin >> n;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }

    memset(dp, -1, sizeof(dp));

    ll ans = max(f(0), f(1));

    cout << ans << '\n';
}

int main() {
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);

    while (tt--) {
        solve();
    }
    
    return 0;
}
