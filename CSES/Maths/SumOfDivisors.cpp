#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <algo/debug.h>
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

ll mod_pow(ll a, ll b) {
    ll ans = 1;

    while (b) {
        if ((b & 1)) {
            ans = (1LL * ans * a) % mod;
        } 
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return ans;
}
// The answer for this problem will be:
// summation from i = 1 to n (i * floor(n / i))
// As we need to find the sum of all the divisors of the numbers from 1 to n.
// Then for number x, it will be divisor of floor(n / x) numbers <= n, so we just want to add
// x * floor(n / x)

// For finding the sum efficiently, we can group the numbers
// let floor(n / i) = x,
// then upper bound for i, will be floor(n / x) and the lower bound will be
// floor(n / (x + 1)) + 1
// Then the x * (sum[lower_bound to upper_bound]) will contribute to the answer.

void solve() {
    ll n;
    cin >> n;
    ll x = n;
    ll ans = 0;

    auto f = [&](ll x) -> ll {
        if (x <= 0) return 0;
        ll ans = x % mod;
        ans = (ans * ((x + 1) % mod)) % mod;
        return (ans * mod_pow(2, mod - 2)) % mod;  // (x*(x+1)/2) % mod
    };

    while (x) {
        ll l = n / (x + 1) + 1, r = n / x;
        if (l == 0) l = 1; // for first number, i.e., for x = n

        ll temp = (f(r) - f(l - 1) + mod) % mod;
        ans = (ans + (temp * (x % mod)) % mod) % mod;

        x = n / (r + 1);
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