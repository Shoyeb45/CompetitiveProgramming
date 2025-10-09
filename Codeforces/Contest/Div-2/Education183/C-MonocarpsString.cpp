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
    int n;
    string _s;
    cin >> n >> _s;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (_s[i] == 'a') {
            a[i] = 1;
        } else {
            a[i] = -1;
        }
        s += a[i];
    }
    
    if (s == 0) {
        cout << 0 << "\n";
        return;
    }
    map<int, int> mp;
    mp[0] = -1;
    int pref = 0;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        pref += a[i];
        if (mp.find(pref - s) != mp.end()) {
            int j = mp[pref - s];
            ans = min(ans, i - j);
        }
        mp[pref] = i;
    }
    cout << (ans == INT_MAX || ans == n ? -1 : ans) << "\n";
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