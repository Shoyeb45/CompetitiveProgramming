#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

vector<vector<int>> a(8, vector<int> (8, 0));
ll dp[9][9];

ll f(int i, int j) {
    if (i < 0 || j < 0 || i >= 8 || j >= 8) {
        return INT64_MAX / 2;
    }

    if (i == 0 && j == 7) {
        return a[i][j];
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    ll ans = a[i][j];
    ll temp1 = ans + f(i - 1, j);
    ll temp2 = ans + f(i, j + 1);
    ll temp3 = ans + f(i - 1, j + 1);

    ans = min({temp1, temp2, temp3});
    return dp[i][j] = ans;
}

void solve() {
    for (auto &x : a) {
        for (auto &y : x) {
            cin >> y;
        }
    }   
    memset(dp , -1, sizeof(dp));
    cout << f(7, 0) << "\n"; 
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