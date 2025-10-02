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

// This is also good question, my complicated approach didn't work, the correct approach is
// just enumerate all the non-empty subsets of given primes and then add the number of divisors of the product of the primes to the answer 
// if the size of the set is odd, else subtract it.

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k);
    for (ll &x: a) {
        cin >> x;
    }   

    int iter = (1 << k);
    ll ans = 0;
    
    for (int i = 1; i < iter; i++) {
        ll prod = n;
        int num_bits = 0;

        for (int j = 0; j < k; j++) {
            int bit = ((1 << j) & i);
            if (bit) {
                num_bits++;
                prod /= a[j];
            }
        }   

        if (num_bits % 2 == 0) {
            ans -= prod;
        } else {
            ans += prod;
        }
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