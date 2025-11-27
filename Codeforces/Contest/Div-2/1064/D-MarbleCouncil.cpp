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

    map<int, int> mp;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        mp[x]++;
    }

    vector<int> a;
    int mx_c = INT_MIN;
    for (auto& it: mp) {
        a.push_back(it.second);
        mx_c = max(mx_c, it.second);
    }
    sort(range(a));
    debug(mx_c);
    vector dp(a.size() + 1, vector<ll>(mx_c));

    std::function<ll(int, int)> f = [&](int idx, int sum) -> int {
        if (idx == a.size()) {
            return 0;
        }

        int ans = f(idx + 1, sum);
        if (sum - a[idx] >= 0) {
            ans += 1 + f(idx + 1, sum - a[idx]);
        }
        return ans;
    };
    cout << f(0, mx_c) << "\n";
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
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}