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
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        mp[x]++;
    }   

    vector<ll> rem;
    for (auto &it: mp) {
        if (it.second == 1) {
            // only one side, insert in remaining 
            rem.push_back(it.first);
        } else {
            // if odd side, insert one in remaining
            if (it.second % 2 == 1){
                mp[it.first]--;
                rem.push_back(it.first);
            }            
        }
    }

    // remove all from mp, which have freq = 1
    for (auto x: rem) {
        if (mp[x] == 1) {
            mp.erase(x);
        }
    }
   
    ll ans = 0;
    ll sides = 0;
    sort(rem.rbegin(), rem.rend());
    for (auto &it: mp) {
        ans += 1LL * it.first * it.second;
        sides += it.second;
    }

    int i = 0;
    // polygon inequality, and since rem[i] > rem[i + 1], so if one satisfies then all other must
    for (;i < rem.size(); i++) {
        if (rem[i] < ans) {
            break;
        }
    }
    // we just have 2 sides and no remaining
    if (sides <= 2 && i >= rem.size()) {
        cout << 0 << "\n";
        return;
    }
    if (i < rem.size()) {
        ans += rem[i++];
    }
    if (i < rem.size() && ans > rem[i]) {
        ans += rem[i];
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

    while (tt--) {
        solve();
    }

    return 0;
}