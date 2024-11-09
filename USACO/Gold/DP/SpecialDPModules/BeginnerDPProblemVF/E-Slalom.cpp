#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
ll dp[101][101];
vector<vector<int>> a;

ll f(int i, int j) {
    if (i == n - 1) {
        return a[i][j];
    }

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    ll ans = a[i][j];
    ll temp1 = ans + f(i + 1, j);
    ll temp2 = ans + f(i + 1, j + 1);
    ans = max (temp1, temp2);
    
    return dp[i][j] = ans;
}

void solve() {
    cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0, x; j < i + 1; j++) {
            cin >> x;
            a[i].push_back(x);
        }
    }    
    memset(dp, -1, sizeof(dp));
    cout << f(0, 0) << "\n";
}

int main() {
    NFS
    freopen("slalom.in", "r", stdin);
    freopen("slalom.out", "w", stdout);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}