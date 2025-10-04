#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <algo/debug.h>
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
    int n, k1, k2, d1, d2;
    cin >> n >> k1 >> k2 >> d1 >> d2;
    
    int ans = 0;

    if (k1 > d1) {
        ans = max(ans, n - d1);
    } else if (k1 < d1) {
        ans = max(ans, d1);
    }

    if (k2 > d2) {
        ans = max(ans, n - d2);
    } else if (k2 < d2) {
        ans = max(ans, d2);
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