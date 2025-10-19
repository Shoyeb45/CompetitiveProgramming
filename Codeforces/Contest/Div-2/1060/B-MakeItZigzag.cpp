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
    vector<int> a(n);
    for (int &i: a) {
        cin >> i;
    }   
    vector<int> mx(n);
    mx[0] = a[0];
    for (int i = 1; i < n; i++) {
        mx[i] = max(mx[i - 1], a[i]);
    }

    int ans = 0;
    for (int i = 1; i < n; i += 2) {
        bool left = a[i] <= a[i - 1];
        bool right = i + 1 < n && a[i] <= a[i + 1];

        if (left) {
            a[i] = mx[i];
            if (a[i] <= a[i - 1]) {
                ans++;
                a[i - 1]--;
            }
        } 
        if (right) {
            a[i] = mx[i];
            if (a[i + 1] >= a[i]) {
                int op = a[i + 1] - a[i] + 1;
                ans += op;
                a[i + 1] -= op;
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