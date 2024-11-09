#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, m;

ll dp[51][51];
ll f(int i, int j) {
    if (i >= n || j >= m) {
        return 0;
    }

    if (i == n - 1 && j == m - 1) {
        return 1;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    ll ans = f(i + 2, j + 1);
    ans += f(i + 1, j + 2);

    return dp[i][j] = ans;
}

void solve() {
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << f(0, 0) << "\n";
}

int main() {
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);
    
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}