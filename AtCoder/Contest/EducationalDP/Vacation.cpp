#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<ll> a[3];
vector<ll> dp[3];

ll f(int idx, int prev = -1) {
    if(idx == n) {
        return 0;
    }

    if(prev != -1 && dp[prev][idx] != -1) {
        return dp[prev][idx];
    }

    ll pick = 0;
    
    for(int i = 0; i < 3; i++) {
        if(i != prev) {
            pick = max(pick , a[i][idx] + f(idx + 1, i));
        }
    }
    return prev == -1? pick: dp[prev][idx] = pick;
}

void solve() {
    cin >> n;
    for(int i = 0; i < 3; i++) {
        a[i].resize(n);
        dp[i].resize(n + 1, -1);
    }    

    for(int i = 0; i < n; i++) {
        cin >> a[0][i] >> a[1][i] >> a[2][i];
    }

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