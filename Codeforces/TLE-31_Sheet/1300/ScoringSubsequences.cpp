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

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }   
    vector<int> ans;
    int ones = 0;
    for (int i = 1; i <= n; i++) {
        int low = 1, high = i;
        int j = i;
        debug(i);
        while (low <= high) {
            int mid = (low + high) / 2;
            int idx = (i - mid + 1);
            debug(mid, idx);
            if (a[mid] / idx >= 1) {
                j = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans.push_back(i - j + 1);
    }
    for (auto x: ans) {
        cout << x << " ";
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

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}