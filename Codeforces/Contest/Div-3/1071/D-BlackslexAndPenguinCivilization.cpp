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
    cin >> n;
    set<int> a;

    for (int i = 0; i < (1 << n); i++) {
        a.insert(i);
    }

    int ans = *a.rbegin();

    while (ans) {
        a.erase(ans);
        cout << ans << " ";
        int bits = (int) log2(ans) + 1;

        int extra = n - bits;
        for (int i = 0; i < (1 << extra); i++) {
            int x = (i << bits);
            if (a.count(ans | x)) {
                cout << (ans | x) << " ";
                a.erase(ans | x);
            }
        }
        ans = (ans >> 1);
    }

    for (auto x: a) {
        if (x & 1) {
            cout << x << " ";
        }
    }

    for (auto x: a) {
        if (x % 2 == 0) {
            cout << x << " " ;
        }
    }
    cout << "\n";
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
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}