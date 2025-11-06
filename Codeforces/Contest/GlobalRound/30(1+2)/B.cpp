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
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> even, odd;
    for (ll x : a) {
        if (x % 2 == 0) { 
            even.push_back(x);
        } else {
            odd.push_back(x);
        }
    }

    if (even.size() >= 2) {
        cout << even[0] << " " << even[1] << "\n";
        return;
    }

    if (a[0] == 1) {
        cout << 1 << " " << a[1] << "\n";
        return;
    }

    if (even.size() == 1) {
        ll y = even[0];
        for (ll x : odd) {
            if (x < y && (y % x) % 2 == 0) {
                cout << x << " " << y << "\n";
                return;
            }
        }
    }

    if (odd.size() >= 2) {
        int K = min(100, (int)odd.size());
        for (int i = 0; i < K; i++) {
            for (int j = i + 1; j < (int)odd.size(); j++) {
                ll x = odd[i], y = odd[j];
                if ((y % x) % 2 == 0) {
                    cout << x << " " << y << "\n";
                    return;
                }
            }
        }
    }

    cout << -1 << "\n";
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