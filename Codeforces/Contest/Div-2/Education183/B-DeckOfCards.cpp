#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<char> ans(n, '+');
    int a = 0, b = 0, c = 0;
    if (n == 1) {
        cout << "-\n";
        return;
    }
    for (char ch : s) {
        if (ch == '0') {
            a++;
        } else if (ch == '1') {
            b++;
        } else {
            c++;
        }
    }

    int i, j;
    for (i = 0; i < a; i++) {
        ans[i] = '-';
    }  
    for (j = n - 1; j >= n - b; j--) {
        ans[j] = '-';
    }

    if (n - (a + b) == c) {
        cout << string(n, '-') << "\n";
        return;
    }
    for (int k = 0; k < c; k++) {
        if (i + k >= n || j - k < 0) {
            break;
        }
        ans[i + k] = '?';
        ans[j - k] = '?';
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i];
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
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
