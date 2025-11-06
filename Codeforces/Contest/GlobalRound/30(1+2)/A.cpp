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
    for (auto &x: a) {
        cin >> x;
    }
    ll x;
    cin >> x;
    if (n == 1) {
        cout << (a[0] == x ? "YES\n": "NO\n");
        return;
    }
    for (int i = 1; i < n; i++) {
        ll mn = min(a[i], a[i - 1]), mx = max(a[i], a[i - 1]);
        if (x >= mn && x <= mx) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}