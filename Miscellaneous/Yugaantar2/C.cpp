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

vector<int> primes;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (auto& x: a) 
        cin >> x;
    
    
    ll low = 1, high = 1e18;
    ll ans = -1;

    int iter = 1 << n;
    vector<ll> p_lcm;
    
    for (int i = 1; i < iter; i++) {
        ll lcm = 1;
        int cnt = 0;
        
        for (int bit_idx = 0; bit_idx < n; bit_idx++) {
            int bit = ((1 << bit_idx) & i);
            if (bit) {
                cnt++;

                ll g = gcd(lcm, a[bit_idx]);
                ll t = lcm / g;
                lcm = t * a[bit_idx];
            }
        }
        p_lcm.push_back(((cnt & 1) ? 1: -1) * lcm);
    }
    
    auto check = [&](ll num) -> bool {
        ll to_sub = 0;
        for (auto x: p_lcm) {
            int sign = (x < 0 ? -1: 1);
            to_sub += (ll) sign * (num / abs(x));
        }
        
        debug(num, num - to_sub);
        return (num - to_sub) >= k;
    };

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
}   



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif
    int tt;
    tt = 1;
    // cin >> tt;
    

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}