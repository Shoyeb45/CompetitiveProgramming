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
    string s;
    cin >> s;
    if (s == "first") {
        int n;
        cin >> n;
        string ans = "";
        while(n--) {
            int x;
            cin >> x;
            ans += x % 26 + 'a';
        }
        cout << ans << "\n";
    } else {
        string t;
        cin >> t;
        vector<int> a;
        for (char ch: t) {
            int x = ch - 'a';
            x = x == 0? 26: x;
            a.push_back(x);
        } 
        cout << a.size() << "\n";
        for (auto p: a) {
            cout << p << " ";
        }
        cout << "\n";
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

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}