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
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }   
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int ones = (int) (a[j][n - i - 1] == '1') + (int) (a[i][j] == '1') + (int) (a[n - i - 1][n - j - 1] == '1') + (a[n - j - 1][i] == '1');
            debug(ones);
            if (ones <= 4 - ones) {
                ans += ones;
                a[i][j] = a[j][n - i - 1] = a[n - i - 1][n - j - 1] = a[n - j - 1][i] = '1';
            } else {
                ans += 4 - ones;
                a[i][j] = a[j][n - i - 1] = a[n - i - 1][n - j - 1] = a[n - j - 1][i] = '0';
            }
        }
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

    while (tt--) {
        solve();
    }

    return 0;
}