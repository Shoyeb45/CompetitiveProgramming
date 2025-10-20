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

vector<int> primes;

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

void solve() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    int ans = 1;
    auto it = upper_bound(range(primes), n);
    it--;
    int total_idx = it - primes.begin();
    int low = 0, high = total_idx;
    int first = total_idx;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if ((ll) primes[mid] * primes[mid] > n) {
            // debug("hi");
            first = mid;
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << total_idx - first + 2 << "\n"; 
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