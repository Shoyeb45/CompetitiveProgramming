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

// side -> 1 : right, 0 : left
int check(int side, vector<int> &a) {
    int n = a.size();
    vector<int> capes(n);
    capes[0] = side;
    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i - 1]) == 0) {
            capes[i] = 1 - capes[i - 1];
        } else {
            capes[i] = capes[i - 1];
        }
    }

    // debug(capes);
    // check, suff -> stores number of right capes
    vector<int> suff(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] + (capes[i] == 1);
    }

    int l = 0;
    for (int i = 0; i < n; i++) {
        // valid if, number of right capes from (i + 1) + 1 + number of left capes till (i - 1) == a[i]
        if (l + suff[i + 1] + 1 != a[i]) {
            return false;
        }
        l += (capes[i] == 0);
    }

    return true;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }   

    int ans = check(0, a) + check(1, a);
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