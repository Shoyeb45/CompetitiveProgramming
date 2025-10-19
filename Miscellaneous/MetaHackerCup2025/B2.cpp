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

ll fact[61];
map<ll, int> factorize(ll n) {
    map<ll, int> factors;
    if (n % 2 == 0) {
        int cnt = 0;
        while (n % 2 == 0) {
            n /= 2;
            cnt++;
        }
        factors[2] = cnt;
    }

    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            factors[i] = cnt;
        }
    }
    if (n > 1) {
        factors[n] = 1;
    }
    return factors;
}

void get_divisors(int idx, vector<ll> &primes, vector<ll> &max_exponents, vector<int> &curr_exp, ll curr_val, vector<pair<ll, vector<int>>> &results) {
    if (idx == primes.size()) {
        results.emplace_back(curr_val, curr_exp);
        return;
    }
    ll p = primes[idx];
    int max_e = max_exponents[idx];
    ll power = 1;
    for (int e = 0; e <= max_e; ++e) {
        curr_exp.push_back(e);
        get_divisors(idx + 1, primes, max_exponents, curr_exp, curr_val * power, results);
        curr_exp.pop_back();
        if (e < max_e) {
            power *= p;
        }
    }
}

ll mod_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) { 
            res = (ll)(res * base) % mod;
        }
        base = (ll)(base * base) % mod;
        exp >>= 1;
    }
    return res;
}

ll binom_coeff(ll n, ll e) {
    if (e == 0) {
        return 1;
    }
    ll num = 1;
    for (int i = 0; i < e; ++i) {
        ll term = (n + i) % mod;
        num = (ll)num * term % mod;
    }
    ll den = fact[e];
    ll inv_den = mod_pow(den, mod - 2, mod);
    return (num * inv_den) % mod;
}
ll f(ll n, vector<int>& exp_vec) {
    ll res = 1;
    for (int e : exp_vec) {
        if (e == 0) continue;
        res = (res * binom_coeff(n, e)) % mod;
    }
    return res;
}

void solve(int tc) {
    ll n, a, b;
    cin >> n >> a >> b;
    cout << "Case #" << tc << ": ";
    if (b == 1) {
        if (a >= 1) {
            cout << 1 << "\n"; 
        } else {
            cout << 0 << "\n";
        }
        return;
    }
    map<ll, int> factors_b = factorize(b);
    vector<ll> primes, max_exponents;
    for (auto it: factors_b) {
        primes.push_back(it.first), max_exponents.push_back(it.second);
    }

    vector<pair<ll, vector<int>>> divisors;
    vector<int> curr_exp;
    get_divisors(0, primes, max_exponents, curr_exp, 1, divisors);

    ll total = 0;
    for (auto& it : divisors) {
        ll d = it.first;
        vector<int> exp_d = it.second;
        if (d > a) continue;

        vector<int> exp_Bd;
        for (int i = 0; i < (int)primes.size(); ++i) {
            exp_Bd.push_back(max_exponents[i] - exp_d[i]);
        }
        ll f1 = f(n, exp_d);
        ll f2 = f(n, exp_Bd);
        total = (total + (f1 * f2) % mod) % mod;
    }
    cout << total << '\n';
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("input_b2.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    fact[0] = 1;
    for (int i = 1; i <= 60; ++i) {
        fact[i] = (fact[i-1] * i) % mod;
    }

    for (int i = 1; i <= tt; i++) {
        solve(i);
    }

    return 0;
}