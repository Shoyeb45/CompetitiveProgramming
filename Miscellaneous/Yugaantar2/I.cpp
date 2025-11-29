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
    vector<ll> a(n);
    map<ll, set<int>> mp;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = x;
        mp[x].insert(i);
    }

    vector<ll> ans = a;
    
    debug(ans);
    for (int i = 0; i < n; i++) {
        if (mp[a[i]].size() == 1) continue;

        ll x = a[i];
        int j = *mp[x].rbegin();
        debug(x, j);
        if (j == i) continue;

        while (i <= j) {
            ans[i] = x;
            i++;
        }
        i--;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}   



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif
    int tt;
    tt = 1;
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}