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
    for (ll &x: a) cin >> x;

    ll sum = 0;

    for (int i = 1; i < n; i++) sum += labs(a[i] - a[i - 1]);
    debug(sum);

    ll ans = min(sum - labs(a[1] - a[0]), sum - labs(a[n - 1] - a[n - 2]));
    debug(ans);

    for (int i = 1; i < n - 1; i++) {
        ll new_sum = sum - (abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1])) + abs(a[i + 1] - a[i - 1]);
        ans = min(ans, new_sum);
    }
    cout << ans << "\n";
}      



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}