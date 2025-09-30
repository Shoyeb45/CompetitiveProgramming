#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


vector<int> prime;

map<ll, int> prime_factors(ll d) {
    map<ll, int> ans;

    for (ll p : prime) {
        if (1LL * p * p > d) break;
        while (d % p == 0) {
            ans[p]++;
            d /= p;
        }
    }
    if (d > 1) ans[d]++;  
    return ans;
}


void solve() {
    ll a, q, d;
    cin >> a >> q;
    while (q--) {
        cin >> d;
        // find prime factors
        map<ll, int> mp = prime_factors(d);
       
        ll ans1 = 0;
        ll ans2 = 1;
        bool all_even = true;
        for (auto it: mp) {
            ans2 = (ll) (1LL * ans2 * (it.second + 1));
            ans1 += it.second;
            if (it.second % 2 == 1) {
                all_even = false;
            }
        }

        cout << ans1 << " " << ((ans2 + (ll) all_even) >> 1) << "\n";
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
    // cin >> tt;
    const int N = 100000 + 1;

    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < N; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (ll j = 2 * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    while (tt--) {
        solve();
    }

    return 0;
}