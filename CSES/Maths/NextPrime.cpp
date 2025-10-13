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


// The count of prime number between 1 to n is n / logn. So the gap between consecutive primes will not be much
// Hence we can check prime one by one, and the maximum gap between two consecutive primes is 540 for the number less than 1e12.

// We can significantly drop the complexity by using sieve. from 0.57 second to 0.12 second
 
vector<ll> primes;

bool is_prime(ll x) {
    if (x < 2) {
        return false;
    }
    if (x == 2 || x == 3) {
        return true;
    }
    if (x % 2 == 0) {
        return false;
    }

    for (ll i: primes) {
        if (i == x) {
            return true;
        }
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    if (n <= 1) {
        cout << 2 << "\n";
        return;
    }
    if (n == 2) {
        cout << 3 << "\n";
        return;
    }


    for (ll np = n + 1; np <= n + 600; np++) {
        if (is_prime(np)) {
            cout << np << "\n";
            return;
        }
    }
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

    const int N = 1e6 + 1;
    bool is_prime[N];
    fill(is_prime, is_prime + N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            primes.push_back((ll) i);
            for (ll j = 1LL * i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    while (tt--) {
        solve();
    }

    return 0;
}