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
    vector<int> p(n + 1);
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        a[i + 1] = i + 1;
        cin >> p[i + 1];
    }
    auto f = [&]() -> void {
        for (int i = 1; i <= n; i++) {
            swap(a[i], a[p[i]]);
        }
    };
    f();
    f();
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}