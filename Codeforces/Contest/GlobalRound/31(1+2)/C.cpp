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
    int n, k;
    cin >> n >> k;
    
    auto is_setable = [&](int num, int idx) -> bool {
        num = (num | (1 << idx));
        // debug(num, idx);
        return num <= n;
    };
 
    if (k % 2 == 0) {
        for (int i = 0; i < k - 2; i++)
            cout << n << " ";
        
        int x = 0, y = 0;
        int idx;
        for (idx = 31; idx >= 0; idx--) {
            if (((1 << idx) & n)) break;
        }

        debug(idx);
        auto chk = [&]() -> void {
            int mx = max(x, y), mn = min(x, y);
            x = mn, y = mx;
        };
        for (int i = idx; i >= 0; i--) {
            bool bit = ((1 << i) & n);

            debug(i, bit, x, y);
            if (bit) {
                if (is_setable(x, i)) {
                    x = (x | (1 << i));
                    chk();
                    continue;
                }
                else if (is_setable(y, i)) {
                    y = (y | (1 << i));
                    chk();
                    continue;
                }
            } else {
                if (is_setable(x, i) && is_setable(y, i)) {
                    x = (x | (1 << i));
                    y = (y | (1 << i));
                    chk();
                }
            }
        }
        debug(x, y);
        if (x + y >= n) {
            cout << x << " " << y << "\n";
        } else {
            cout << n << " " << 0 << "\n";
        }
        return;
    } 

    for (int i = 0; i < k; i++) {
        cout << n << " \n"[i == k - 1];
    }
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
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}