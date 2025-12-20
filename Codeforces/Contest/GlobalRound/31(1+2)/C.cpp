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

    vector<int> a(k);

    int mx_bit = -1;
    for (int i = 30; i >= 0; i--) 
        if (((1 << i) & n)) {
            mx_bit = i;
            break;
        }
        
    vector<bool> tight(k, true);

    for (int idx = mx_bit; idx >= 0; idx--) {
        int mask = (1 << idx);
        bool bit = ((1 << idx) & n);

        if (bit) {
            if (k % 2 == 1) {
                for (int i = 0; i < k; i++) {
                    a[i] |= mask;
                }
            } else {
                // set all bit to 1 leaving 1 number, which is tight
                int j = -1;
                for (int i = 0; i < k; i++) {
                    if (tight[i]) {
                        j = i;
                        break;
                    }
                }
                debug(j);
                j = (j == -1 ? 0: j);

                for (int i = 0; i < k; i++) {
                    if (i != j) {
                        a[i] |= mask;
                    }
                }
            }

            for (int i = 0; i < k; i++) {
                if (tight[i] && ((a[i] >> idx) & 1) == 0) {
                    tight[i] = false;
                }
            }
        } else {
            vector<int> loose;
            for (int i = 0; i < k; i++) {
                if (!tight[i]) {
                    loose.push_back(i);
                }
            }
            if (loose.size() % 2 == 1 && !loose.empty())
                loose.pop_back();

            for (auto x: loose) {
                a[x] |= mask;
            }
        }

    }

    for (int i = 0; i < k; i++) {
        cout << a[i] << " \n"[i == k - 1];
    }
}   



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/Users/Keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/Users/Keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/Users/Keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}