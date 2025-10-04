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

int a[100];
int n;

bool all_zero() {
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    while (true) {
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) {
                mn = min(mn, a[i]);
            }
        }        

        bool is_neg = false;
        for (int i = 0; i < n; i++) {
            if (a[i] - mn < 0) {
                is_neg = true;
                continue;  
            } 
            a[i] -= mn;
        }
        ans += 1 + (int) is_neg;
        if (all_zero()) {
            break;
        }
    }
    cout << ans << '\n';
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