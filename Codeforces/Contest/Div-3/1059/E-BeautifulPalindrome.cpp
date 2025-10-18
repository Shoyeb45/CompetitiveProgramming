#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
const ll mod = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    set<int> st;
    for (int &x: a) {
        cin >> x;
        st.insert(x);
    }

    int ans[3];
    if (st.size() == n) {
        for (int i = 0; i < 3; i++) {
            ans[i] = a[i];
        }
    } else {
        ans[2] = a.back();
        for (int i = 1; i <= n; i++) {
            if (st.find(i) == st.end()) {
                ans[0] = i;
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (i != ans[0] && i != ans[2]) {
                ans[1] = i;
                break;
            }
        }
    }

    int i = 0;
    while (k--) {
        cout << ans[i] << " ";
        i = (i + 1) % 3;
    }
    cout << "\n";
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