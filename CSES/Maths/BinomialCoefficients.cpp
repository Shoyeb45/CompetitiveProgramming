#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
const ll mod = 1000000007;
const int N = 1e6 + 1;
static ll factorial[N];


ll mod_pow(ll base, ll power) {
    ll ans = 1;
    while (power) {
        if ((power & 1)) {
            ans = (ll)ans * base % mod;
        }
        base = (ll) base * base % mod;
        power >>= 1;
    }
    return ans;
}

void solve() {
    int a, b;
    cin >> a >> b;
    
    ll numerator = factorial[a] % mod;
    ll denominator = (ll)factorial[b] * factorial[a - b] % mod;
    ll ans = (ll)numerator * mod_pow(denominator, mod - 2) % mod;
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
    cin >> tt;
    fill(factorial, factorial + N, 0);
    factorial[0] = factorial[1] = 1;
    for (int i = 2; i < N; i++) {
        factorial[i] = (ll)i * factorial[i - 1] % mod; 
    } 
    
    while (tt--) {
        solve();
    }

    return 0;
}