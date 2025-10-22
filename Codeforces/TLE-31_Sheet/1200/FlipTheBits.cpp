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
    string s, t;
    cin >> s >> t;
    vector<int> ones(n);
    ones[0] = (s[0] == '1');

    for (int i = 1; i < n; i++) {
        ones[i] = ones[i - 1] + (s[i] == '1');
    }

    int flip = 0;
 
    for (int i = n - 1; i >= 0; i--) {
        if (t[i] != s[i]) {
            // if flip is odd, then contiue
            if (flip % 2 == 1) {
                continue;
            }
            if (ones[i] == i + 1 - ones[i]) {
                flip++;
                continue;
            }
            cout << "NO\n";
            return;
        } else {
            if (flip % 2 == 0) {
                continue;
            }
            if (ones[i] == i + 1 - ones[i]) {
                flip++;
                continue;
            }
            cout << "NO\n";
            return;
        }
    }   
    cout << "YES\n";
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