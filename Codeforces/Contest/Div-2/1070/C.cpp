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

    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ((x & 1) ? odd : even).push_back(x);
    }

    sort(rrange(odd));
    sort(rrange(even));

    if (odd.empty()) {
        for (int i = 1; i <= n; i++) 
            cout << 0 << " \n"[i == n];
        return;
    }
    
    if (even.empty()) {
        for (int i = 1; i <= n; i++) {
            cout << ((i & 1) ? odd.front() : 0) << " \n"[i == n];
        }
        return;
    }

    if (odd.size() == 1) {
        ll ans = odd.front();
        cout << ans << " ";
        for (int i = 0; i < n - 1; i++) {
            cout << (ans += even[i]) << " ";
        }
        cout << "\n";
        return;
    }

    n = odd.size(); 
    int m = even.size();

    ll ans = odd.front();
    cout << ans << " ";
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        sum += even[i];
        cout << (ans + sum) << " ";
    }


    int parity = (m + 2) % 2;
    for (int i = m + 2; i <= m + n - 1; i++) {
        if (parity == i % 2) {
            cout << ans + (sum - even.back()) << " ";
        } else {
            cout << ans + sum << " ";
        }
    }
    cout << ((odd.size() & 1) ? ans + sum : 0) << "\n";
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