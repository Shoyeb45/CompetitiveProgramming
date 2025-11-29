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

    vector<int> a(n), b(m);

    map<int, set<int>> mp;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].insert(i);
    }

    for (int j = 0; j < m; j++) cin >> b[j];

    vector<int> oc;
    int j = 0;
    vector<bool> ans(n, false);

    for (int i = 0; i < n; i++) {
        if (a[i] == b[j]) {
            oc.push_back(i);
            ans[i] = 1;
            j++;
        }
    }

    j = n - 1;
    for (int k = (int) oc.size() - 1; k >= 0; k--) {
        int i = oc[k];

        auto it = mp[a[i]].lower_bound(oc[k]);

        if (it == mp[a[i]].end()) continue;

        for (; it != mp[a[i]].end() && *it < j; it = next(it)) {
            ans[*it] = 1;
        }
        j = *mp[a[i]].rbegin() - 1;
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