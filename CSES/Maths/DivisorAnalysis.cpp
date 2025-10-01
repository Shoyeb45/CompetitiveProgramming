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
const int N = (int) 1e5;
int n;
ll x[N], k[N];



// Very beautiful question - Took entire day to solve, still saw the solution from USACO

// x_i -> prime with power k_i
// First finding the count of divisors, for each prime x_i, we can take that prime 0 times, 1 times, 2 times or k_i times.
// so the answer will be mul from i = 1 to n [k_i + 1]

// Now sum of the divisor.
// each divisor can be expressed as: 
// d = mult i = 1 to n {x_i^(e_i)}, where,  k_i >= e_i >= 0, then we can sum them up and factor out common terms and we see that
// multiplication from i = 1 to n(x_i^(k_i + 1) - 1 / (k_i - 1))

// product of the divisor, it gave me hard time
// for each i, x_i ^ {k_i * (k_i + 1) / 2  *  summation of all j != i (k_j + 1)}, it can be reduced to n^{d/2}, where n is given number
// and d is number of divisors.

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
ll mod_inv(ll x) {
    return mod_pow(x, mod - 2) % mod;
}

ll mod_mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
} 

ll mod_add(ll a, ll b) {
    a %= mod, b %= mod;
    return (a + b + mod) % mod;
}

ll find_num_of_divisors() {
    ll ans = 1;

    for (int i = 0; i < n; i++) {
        ans = mod_mul(ans, k[i] + 1);        
    }
    return ans % mod;
}



ll gp_sum(ll r, ll n) {
    if (r == 1) {
        return mod_add(n, 1);
    }
    ll numerator = mod_add(-1, mod_pow(r, n + 1)) % mod;
    ll denominator = mod_inv(r - 1);
    return mod_mul(numerator, denominator) % mod;
}

ll find_sum_of_divisors() {
    ll ans = 1;

    for (int i = 0; i < n; i++) {
        ans = mod_mul(ans, gp_sum(x[i], k[i]));
    }
    return ans % mod;
}

ll find_product_of_divisors() {
    // first calculate number of divisors.
    ll ans = 1;
    ll c = 1;
    
    for (int i = 0; i < n; i++) {
        ans = mod_mul(
            mod_pow(ans, k[i] + 1), // P_{i-1}^{k[i] + 1}
            mod_pow(mod_pow(x[i], (1LL * k[i] * (k[i] + 1)) / 2), c)  // x_i^{(k_i * (k_i + 1) / 2) & C_{i-1}}
        );
        c = c * (k[i] + 1) % (mod - 1);
    }
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> k[i];
    }    
    
    cout << find_num_of_divisors() << " " << find_sum_of_divisors() << " " << find_product_of_divisors() << "\n";
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