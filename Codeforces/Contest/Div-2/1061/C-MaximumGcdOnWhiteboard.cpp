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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, int> mp;
    for (ll &x: a) {
        cin >> x;
        mp[x]++;
    }   

    
    if (count(range(a), 1) > k) {
        cout << 1 << "\n";
        return;
    }
   
    vector<ll> di(n + 3);
    sort(range(a));
    di[1] = n;

    for (int i = 2; i <= n; i++) {
        for (int d = i; d <= n; d += i) {
            if (d > 4 * i) break;
            di[i] += mp[d];
        }
    }
    for (int x = n; x >= 1; x--) {
        auto it = upper_bound(range(a), 4 * x);
        ll cnt = a.end() - it;  
        if (max(0LL, n - di[x] - cnt) <= k) {
            cout << x << "\n";
            return;
        }
    }
    cout << 1 << "\n";

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