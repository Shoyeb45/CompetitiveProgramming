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
    multiset<ll> swords;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        swords.insert(x);
    }   
    vector<pair<ll, ll>> stage1, stage2;
    {
        vector<ll> temp(m);
        for (int i = 0; i < m; i++) {
            cin >> temp[i];
        }     
        for (int i = 0; i < m; i++) {
            ll x;
            cin >> x;
            if (x == 0) {
                stage2.push_back({temp[i], x});
            }  else {
                stage1.push_back({temp[i], x});
            }
        }
    }
    sort(range(stage1));
    ll ans = 0;
    for (auto& [b, c]: stage1) {
        auto it = swords.lower_bound(b);
        if (it == swords.end()) {
            break;
        }
        ans++;
        ll ele = max(c, *it);
        swords.erase(it);
        swords.insert(ele);
    }
    sort(range(stage2));
    for (auto& [b, _]: stage2) {
        auto it = swords.lower_bound(b);
        if (it == swords.end()) {
            break;
        }
        ans++;
        swords.erase(it);
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



3.
