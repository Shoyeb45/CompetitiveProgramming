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
    vector<ll> p_odd(n + 1), p_even(n + 1);
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        p_odd[i] = p_odd[i - 1], p_even[i] = p_even[i - 1];
        p_odd[i] += (i % 2 == 1) * x;
        p_even[i] += (i % 2 == 0) * x;
    }
    set<ll> st;
    st.insert(0);
    for (int i = 1; i <= n; i++) {
        ll diff = p_odd[i] - p_even[i];
        if (st.find(diff) != st.end()) {
            cout << "YES\n";
            return;
        }
        st.insert(diff);
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

    while (tt--) {
        solve();
    }

    return 0;
}