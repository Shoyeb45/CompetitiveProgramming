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
    ll n, m, c;
    cin >> n >> m >> c;   
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        mp[x]++;
    }
    vector<ll> idxs;
    vector<ll> b;
    if (mp.begin() -> first != 0) {
        idxs.push_back(0);
        b.push_back(0);
    }
    for (auto it: mp) {
        idxs.push_back(it.first);
        b.push_back(it.second);
    }
    if (mp.rbegin() -> first != m) {
        idxs.push_back(m);
        b.push_back(0);
    }
    int k = idxs.size();
    for (int i = 0; i < k; i++) {
        b.push_back(b[i]);
    }
    partial_sum(range(b), b.begin());
    ll ans = 0;
    for (int i = 1; i < k; i++) {
        int pos = lower_bound(range(b), c + b[i - 1]) - b.begin();
        ans += (ll) (b[pos] - b[i - 1]) * (idxs[i] - idxs[i - 1]);
    }
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
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}