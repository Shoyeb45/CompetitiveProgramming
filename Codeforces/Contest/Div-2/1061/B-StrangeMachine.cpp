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
    int n, q;
    string s;
    cin >> n >> q >> s;

    bool all_a = (count(range(s), 'A') == n);
    auto query = [&](ll x) -> void {
        if (all_a) {
            cout << x << '\n';
            return;
        }
        ll ans = 0;
        for (int i = 0; i < n; i = (i + 1) % n) {
            if (s[i] == 'A') {
                x--;
            } else {
                x /= 2;
            }
            ans++;
            if (x == 0) {
                break;
            }
        }
        cout << ans << "\n";
    };

    while (q--) {
        ll x;
        cin >> x;
        query(x);
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

    while (tt--) {
        solve();
    }

    return 0;
}