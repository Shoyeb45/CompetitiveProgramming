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
const ll mod = (1 << 20);
ll n, a, b, m;
string s;

class MedianFinder {
public:
    multiset<ll> ms[10];
    vector<ll> extra_strength;
    int total_num = 0;
    MedianFinder() {
        extra_strength.resize(10);
    }

    void add_num(ll x, int clan) {
        ms[clan].insert(x - extra_strength[clan]);
        total_num++;
    }

    ll count_leq(ll x) const {
        ll cnt = 0;
        for (int i = 0; i < 10; i++) {
            if (!ms[i].empty()) {
                cnt += distance(ms[i].begin(), ms[i].upper_bound(x - extra_strength[i]));
            }
        }
        return cnt;
    }

    ll find_median() {
        if (total_num == 0) {
            return 0;
        }
        ll lo = -2e9, hi = 2e9; 
        ll target = (total_num + 1) / 2;
        ll ans = lo;

        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            if (count_leq(mid) >= target) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    void shift(int clan, ll delta) {
        extra_strength[clan] += delta;
    }
    
    void remove(ll x, int clan) {
        auto it = ms[clan].find(x - extra_strength[clan]);
        if (it != ms[clan].end()) {
            ms[clan].erase(it);
            total_num--;
        }
    }
};

void solve() {
    cin >> n >> a >> b >> m >> s;

    ll x0 = 0;
    ll ans = 0;

    auto strength_val = [&](ll x0) -> ll {
        return ((ll) x0 * a + b) % mod;
    };

    MedianFinder mf;
    
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        ll new_x = strength_val(x0);
        mf.add_num(new_x, s[idx] - '0');
        if (i % m == 0) {
            mf.shift(s[idx] - '0', 1);
            ans += mf.find_median();
        } else {
            ans += mf.find_median();
        }

        x0 = new_x;
        idx = (idx + 1) % s.size();
    }
    cout << ans << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        cout << "Case #" << i << ": "; 
        solve();
    }

    return 0;
}