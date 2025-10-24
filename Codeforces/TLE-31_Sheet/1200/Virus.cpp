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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int &x: a) {
        cin >> x;
    }
    vector<int> diff;
    sort(range(a));
    for (int i = 1; i < m; i++) {
        diff.push_back(a[i] - a[i - 1] - 1);
    }
    diff.push_back(n - (a[m - 1] - a[0] + 1));
    sort(rrange(diff));

    int days = 0;
    ll safe = 0;
    for (int &x: diff) {
        x = max(0, x - 2 * days);
        if (x > 0) {
            safe += max(x - 1, 1);
        }
        days += 2;
    }
    cout << n - safe << "\n";
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