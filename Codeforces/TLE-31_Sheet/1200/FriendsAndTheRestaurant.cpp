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
    cin >> n;
    vector<int> s(n), e(n);
    for (auto &x: s) {
        cin >> x;
    }   
    for (auto &x: e) {
        cin >> x;
    }   
    multiset<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++) {
        int diff = e[i] - s[i];
        if (diff >= 0) {
            pos.insert(diff);
        } else {
            neg.push_back(diff);
        }
    }
    sort(neg.rbegin(), neg.rend());
    
    int ans = 0;
    for (auto x: neg) {
        auto it = pos.lower_bound(-x);
        if (it != pos.end()) {
            ans++;
            pos.erase(it);
        }
    }
    cout << ans + pos.size() / 2 << "\n";
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