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
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        mp[x]++;
    }

    ll base = 0;
    vector<ll> odd, even;
    for (auto& [x, c]: mp) {
        base += (ll) x * (c / 2);
        if (c % 2 == 1) {
            odd.push_back(x);
        } else {
            even.push_back(x);
        }
    }
    ll ans = 0;
    for (auto x: odd) {
        if (2 * base > x) {
            ans = max(ans, 2 * base + x);
        }
    }
    for (auto x: even) {
        if (base > x) {
            ans = max(ans, 2 * base);
        }
    }
    for (int i = 1; i < odd.size(); i++) {
        if (odd[i - 1] + 2 * base > odd[i]) {
            ans = max(ans, odd[i - 1] + odd[i] + 2 * base);
        }
    }
    cout << ans << '\n';
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