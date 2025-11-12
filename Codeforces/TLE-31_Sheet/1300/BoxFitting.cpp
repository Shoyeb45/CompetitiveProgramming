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
    ll w;
    cin >> n >> w;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        mp[x]++;
    }
    ll ans = 0;
    ll temp = 0;
    while (!mp.empty()) {
        vector<int> keys_to_be_deleted;
        for (auto it: mp) {
            if (temp == w) {
                ans++;
                temp = 0;
            } 
            if (temp + it.first > w) {
                ans++;
                temp = it.first;
                it.second--;
            } else {
                temp += it.first;
                it.second--;
            }
            if (it.second == 0) {
                keys_to_be_deleted.push_back(it.first);
            }
        }
        debug(keys_to_be_deleted);
        for (auto x: keys_to_be_deleted) {
            mp.erase(x);
        }
    }
    cout << ans << "\n";
}

int main() {
    NFS
    // #ifndef ONLINE_JUDGE
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    // #endif
    int tt;
    tt = 1;
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}