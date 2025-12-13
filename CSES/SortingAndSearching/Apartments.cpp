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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    multiset<int> apartments;

    for (int& i: a) cin >> i;
    
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        apartments.insert(x);
    }

    ll ans = 0;

    sort(range(a));

    for (auto x: a) {
        if (apartments.empty()) break;

        int low = x - k, high = x + k;

        auto low_it = apartments.lower_bound(low);
        auto high_it = apartments.upper_bound(high);

        vector<int> to_del;
        if (high_it != apartments.begin())
            high_it = prev(high_it);

        int cnt = 0;

        for (auto it = low_it; it != next(high_it); it = next(it)) {
            if (*it >= low && *it <= high) {
                to_del.push_back(*it);
                cnt++;
                break;
            }
        }
        if (cnt > 0) 
            ans++;

        for (auto y: to_del) {
            apartments.erase(apartments.find(y));
        }
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
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}