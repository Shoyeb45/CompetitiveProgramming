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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), idx(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        idx[a[i]] = i;
    }
    int ans = 0;
    set<int> st;

    for (int i = 1; i <= k; i++) {
        st.insert(a[i]);
    }
    for (int i = 1; i <= k; i++) {
        ans += st.find(i) == st.end();
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

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}