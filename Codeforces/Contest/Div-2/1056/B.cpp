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
    int n, k;
    cin >> n >> k;
    if (n * n - 1 == k) {
        cout << "NO\n";
        return;
    }   
    int filled = 0;
    vector<vector<char>> ans(n, vector<char>(n));
    int i, j;

    for (i = 0; i < n; i++) {
        bool ok = false;
        for (j = 0; j < n; j++) {
            if (filled == k) {
                ok = true;
                break;
            }
            ans[i][j] = 'U';
            filled++;
        }
        if (ok) {
            break;
        }
    }
    debug(i, j );
    if (i < n && j < n && n - j >= 2) {
        ans[i][j] = 'R', ans[i][j + 1] = 'L';
        for (int k = j + 2; k < n; k++) {
            ans[i][k] = 'L';
        }
        i++;
        if (i < n) {
            for (int k = 0; k < j; k++) {
                ans[i][k] = 'R';
            }
            for (int k = j; k < n; k++) {
                ans[i][k] = 'U';
            }
            i++;
        }
        
    } else if (i < n && j < n) {
        ans[i++][j] = 'D';
        if (i < n) {
            ans[i][0] = 'R', ans[i][1] = 'L';
            for (int j = 2; j < n; j++) {
                ans[i][j] = 'L';
            }
            i++;
        }
    }


    for (; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = 'U';
        }
    }

    cout << "YES\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
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
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}