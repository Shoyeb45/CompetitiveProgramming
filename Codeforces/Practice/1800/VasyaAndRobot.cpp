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

void solve() {
    int n;
    ll x, y;
    string s;
    cin >> n >> s >> x >> y;

    ll total_x = 0, total_y = 0;
    ll l = 0, r = 0, u = 0, d = 0;

    for (auto ch: s) {
        if (ch == 'L' || ch == 'R') {
            total_x++;
            l += ch == 'L', r += ch == 'R';
        } else {
            total_y++;
            u += ch == 'U', d += ch == 'D';
        }
    }

    auto check = [&](ll x, ll tot) -> bool {
        debug(x, tot);
        return (x % 2 == 0 && x / 2 >= 0 && x / 2 <= tot);
    };
    if (!check(total_x + x, total_x) || !check(total_y + y, total_y)) {
        cout  << -1 << "\n";
        return;
    }
    ll req_r = (total_x + x) / 2, req_l = total_x - req_r;
    ll req_u = (total_y + y) / 2, req_d = total_y - req_u;
    
    ll mx = LLONG_MIN, mn = LLONG_MAX;


    if (req_r > r) {
        // convert L to R
        char ch = (req_u > u ? 'D': 'U');
        int total = abs(req_r - r) + abs(req_u - u);
        int k = 0;
        for (ll i = n - 1; i >= 0; i--) {
            if (k == total) {
                break;
            }
            if (s[i] == ch || s[i] == 'L') {
                k++;
                mx = max(i, mx), mn = min(i, mn);
            }
        }
    } else if (req_r < r) {
        // convert R to L
        
        char ch = (req_u > u ? 'D': 'U');
        int total = abs(req_r - r) + abs(req_u - u);
        int k = 0;
        for (ll i = n - 1; i >= 0; i--) {
            if (k == total) {
                break;
            }
            if (s[i] == ch || s[i] == 'L') {
                k++;
                mx = max(i, mx), mn = min(i, mn);
            }
        }
    }
    cout << mx - mn + 1 << "\n";

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

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}