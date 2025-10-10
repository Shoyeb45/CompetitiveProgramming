#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
const ll mod = 1000000007;

void solve() {
    int n;
    cin >> n;
    // vector<int> a(n);
    map<int, ll> mp;

    for (int i = 0, x; i < n; i++) {
        cin >> x;
        mp[x]++;
    } 

    ll ans = 0;
    auto f = [&](ll x, ll y) {
        return (1LL * x * (x - 1)) * y * 1LL / 2;
    };

    for (int x = 1; x <= n; x++) {
        if (mp.find(x) != mp.end()) {
            ll cnt_x = mp[x], cnt_x_1 = mp[x + 1], cnt_x_2 = mp[x + 2];
            ans += 1LL * cnt_x * (cnt_x - 1) * 1LL * (cnt_x - 2) / 6; // x, x, x
            ans += 1LL * cnt_x * (cnt_x_1) * 1LL * (cnt_x_2);  // x, x + 1, x + 2
            ans += f(cnt_x_1, cnt_x); // x + 1, x + 1, x
            ans += f(cnt_x_2, cnt_x); // x + 2, x + 2, x
            ans += f(cnt_x, cnt_x_1); // x, x, x + 1
            ans += f(cnt_x, cnt_x_2); // x, x, x + 2
        }
    }
    // debug(mp);
    cout << ans << "\n";
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