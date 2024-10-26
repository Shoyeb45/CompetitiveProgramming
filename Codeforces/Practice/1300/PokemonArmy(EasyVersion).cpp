#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, q;


ll f(int i, vector<int> &a, vector<vector<ll>> &dp, int isNeg = 1) {
    if(i == n) {
        return 0;
    }

    if(dp[isNeg][i] != -1) {
        return dp[isNeg][i];
    }

    ll pick = 0, notPick = 0;
    if(isNeg) {
        pick += a[i] + f(i + 1, a, dp, 0);
        notPick += f(i + 1, a, dp, isNeg);
    }
    else {
        pick += -a[i] + f(i + 1, a, dp, 1);
        notPick += f(i + 1, a, dp, isNeg);
    }       

    return dp[isNeg][i] = max(pick, notPick);
}
void solve() {
    cin >> n >> q;
    vector<int> a(n);
    for(auto &x: a) {
        cin >> x;
    }   

    vector<vector<ll>> dp(2, vector<ll> (n, -1));

    cout << f(0, a, dp) << "\n";

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
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}