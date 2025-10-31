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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }   
    
    sort(range(a));
    auto check = [&](ll mid) -> bool {
        ll cnt = 0;
        for (int i = 1; i < n; i++) {
            cnt += max(0LL, (a[i] - mid) - (a[i - 1] + mid) + 1);
        }
        return cnt >= k;
    };
    ll low = 0, high = x;
    ll ans = -1;

    while (low < high) {
        ll mid = (low + high) >> 1;
        debug(low, high);
        if (check(mid)) {
            debug(mid);
            low = mid + 1;
            ans = mid;
        } else {
            high = mid;
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

    while (tt--) {
        solve();
    }

    return 0;
}