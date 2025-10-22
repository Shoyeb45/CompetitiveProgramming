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
    int n, m;
    cin >> n >> m;
    vector<int> infe(m);
    for (int i = 0; i < m; i++) {
        cin >> infe[i];
        infe[i]--;
    }   
    sort(range(infe));
    if (n == m) {
        cout << n << "\n";
        return;
    }

    vector<pair<int, int>> vp;
    for (int i = 0; i < m; i++) {
        int low = infe[i];
        int high = infe[i];
        int k = i;
        while ((infe[k] + 1) % n == infe[(k + 1) % m]) {
            high = infe[(k + 1) % m];
            k = (k + 1) % m;
        }
        if (k > i) {
            i = k;
        }
        vp.push_back({low, high});
    }
    if (vp.size() > 1 && vp.back().second == vp.front().second) {
        vp[0].first = vp.back().first;
        vp.pop_back();
    }
    debug(vp);
    vector<int> diff;
    for (int i = 1; i < vp.size(); i++) {
        diff.push_back(vp[i].first - vp[i - 1].second - 1);
    }

    if (!vp.empty()) {
        if (vp.front().first <= vp.front().second) {
            diff.push_back(vp.front().first + n - vp.back().second - 1);
        } else {
            diff.push_back(vp.front().first - vp.back().second - 1);
        }
    }
   
    sort(diff.rbegin(), diff.rend());
    int safe = 0, to_sub = 0;
    debug(diff);
    for (int &x: diff) {
        x = max(0, x - to_sub);
        if (x > 0) {
            safe += max(x - 1, 1);
        }
        to_sub += 4;
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