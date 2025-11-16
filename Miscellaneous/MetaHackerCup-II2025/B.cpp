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
    int n, m;
    cin >> n >> m;
    vector a(n, 0ll), b(m, 0ll);
    map<ll, ll> mp;
    for (auto &x: a) {
        cin >> x;
        mp[x]++;
    }

    ll u = 0;
    for (auto &x: b) {
        cin >> x;
        u += x;
    }
    ll k = (int) mp.size();
    ll sum_f = 0;
    vector<pair<ll, ll>> vp(mp.begin(), mp.end());
    sort(rrange(vp));


    ll pref = 0;
    ll x = INT_MAX;
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        pref += vp[i].second;
        ll sum = (ll) i * (i + 1) / 2;
        ll temp = (u + sum + pref - 1) / pref;
        if (temp > 0 && temp < x) {
            x = temp;
        }
    }
    debug(pref, u, x);
    for (auto i: vp) {
        debug(i);
    }
    if (x == INT_MAX) {
        x = 0;
    }
    for (int i = 0; i < k; i++) {
        if (u == 0 || x == 0) {
            break;
        }
        if ((ll) vp[i].second * x <= u) {
            u -= (ll) vp[i].second * x;
            x--;
            ans += vp[i].second;
        } else {
            break;
        }
    }
    cout << ans << "\n";
}   



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
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