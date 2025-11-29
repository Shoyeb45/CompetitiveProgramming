#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS                                                                                                            \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;


bool check(ll n) {
    vector<ll> a;
    ll x = n;
    ll p = 2;
    while (n != 1) {
        if (n % p == 0) {
            a.push_back(p);
            while (n % p == 0) {
                n /= p;
            }
        }
        p++;
    }
    debug(x, a);
    for (auto &p: a) {
        ll y = (ll) p * p;
        if (x % y != 0) return false;
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll cnt = 0;

    // for (int i = 2; i < 64; i++) {
    //     ll d = (1LL << i);
    //     if (d > n)
    //         break;

    //     ans += d;
    //     debug(d);
    //     cnt++;
    // }

    // for (int i = 3;; i++) {
    //     ll _sq = (ll)i * i;
    //     if (_sq > n)
    //         break;
    //     if ((_sq & (_sq - 1)) == 0) continue;
    //     ans += _sq;
    //     debug(_sq);
    //     cnt++;
    // }
    for (ll i = 1; i <= n; i++) {
        bool chk = check(i);
        if (chk) {
            ans += i;
            cnt++;
            cout << i << "\n";
        }
    }
    cout << cnt << "\n" << ans << "\n";
}

int main() {
    NFS
#ifndef ONLINE_JUDGE
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
    freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
    freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
#endif
    int tt;
    tt = 1;
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}