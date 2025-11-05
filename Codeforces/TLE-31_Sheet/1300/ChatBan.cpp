#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll sum_till_n(int n) {
    if (n <= 0) {
        return 0LL;
    }
    ll ans = n;
    ans = 1LL * ans * (n + 1);
    return ans / 2LL;
}

void solve() {
    ll k, x;
    cin >> k >> x;
    
    ll tot = sum_till_n(k - 1) + sum_till_n(k);
    debug(tot, x);
    if (x >= tot) {
        cout << 2LL * k - 1 << "\n";
        return;
    } 

    ll upper = sum_till_n(k);
    if (x > upper) {
        ll lower = (ll) (x - upper);
         
        ll low = 1, high = k - 1;
        ll ans = k - 1;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll d = (ll) (1LL * mid * k - sum_till_n(mid)); 

            if (d >= lower) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << k + ans << "\n";
    } else {
        ll low = 1, high = k;
        ll ans = 1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            ll d = sum_till_n(mid);
            debug(mid, d);
            if (d >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
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

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}