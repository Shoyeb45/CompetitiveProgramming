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
const int N = 1e4 + 1;

vector<ll> primes;

void sieve() {
    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

map<ll, int> factorize(ll x) {
    map<ll, int> mp;
    if (x == 1) {
        mp[1LL]++;
        return mp;
    }

    for (auto p: primes) {
        if (p > x) {
            break;
        }
        while (x % p == 0) {
            x /= p;
            mp[p]++;
        }
    }
    if (x > 1) {
        mp[x]++;
    }
    return mp;
}

void solve() {
    int n, b;
    cin >> n >> b;
    vector<int> a(n);
    for (auto &it: a) {
        cin >> it; 
    }
    
    ll ans = 1;
    map<ll, int> mp;
    bool is_perf = false;
    bool is_one = false;
    for (int i = 0; i < n; i++) {
        ll x = a[i];
        if (x == 1) {
            if (is_perf || is_one) {
                ans++;
                is_perf = false;
                is_one = true;
                mp.clear();
            }
            is_one = true;
            continue;
        }
        auto factors = factorize(x);
        ll req = 1;
        bool all_even = true;
        for (auto it: factors) {
            if ((it.second & 1)) {
                req = (ll) req * it.first;
                all_even = false;
            } 
        }
        is_perf |= all_even;
        
        if (mp.find(req) != mp.end()) {
            ans++;
            mp.clear(), is_perf = all_even, is_one = false;
        }
        if (is_perf && is_one) {
            ans++;
            mp.clear(), is_one = false, is_perf = true;
        }
        mp[req]++;
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
    cin >> tt;
    sieve();

    while (tt--) {
        solve();
    }

    return 0;
}