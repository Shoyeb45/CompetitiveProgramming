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
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        mp[x]++;
    }    

    vector<pair<ll, ll>> vp(m); // (b_i, c_i)

    for (auto &x: vp) {
        cin >> x.first;
    }
    for (auto &x: vp) {
        cin >> x.second;
    }
    sort(range(vp));
    priority_queue<int> pq;

    ll ans = 0;
    
    int idx = 0;
    while (true) {
        if (mp.empty()) {
            break;
        }
        ll sword = mp.rbegin()->first;
        while (idx < m && sword >= vp[idx].first) {
            pq.push(vp[idx].second);
            idx++;
        }
        if (pq.empty()) {
            break;
        }
        ll c = pq.top();
        pq.pop();
        ans++;
        mp[sword]--;
        if (mp[sword] == 0) {
            mp.erase(sword);
        }
        if (c > 0) {
            mp[max(c, sword)]++;
        }
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
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}