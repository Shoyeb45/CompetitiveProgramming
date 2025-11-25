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
    vector<ll> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    for (int i = 1; i <= n; i++) {
        a.push_back(a[i]);
        b.push_back(b[i]);
    }


    for (int i = 2; i <= 2 * n; i++) {
        b[i] += b[i - 1];
    }

    ll mx = *max_element(a.begin() + 1, a.end());

    ll ans = mx;
    vector<int> indices;

    for (int idx = 1; idx <= n; idx++) {
        if (a[idx] == ans) {
            indices.push_back(idx);
        }
    }

    for (auto idx: indices) {
        for (int i = idx + 1; i < idx + n; i++) {
            ll x = a[i];
            x += b[idx + n - 1] - b[i - 1];
    
            if (x >= mx) {
                ans = min(ans, a[i]);
            } 
        }
    }

    cout << ans << "\n";
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