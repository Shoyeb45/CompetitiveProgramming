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
    int n = s.size();
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1] && s[i] == 'T') {
            cout << "NO\n";
            return;
        }
    }   
    string t = "";
    auto check = [&](string t) -> bool {
        if (t.size() == 2 || t.size() == 0) {
            return true;
        }
        if (t.size() % 2 != 0) {
            return false;
        }
        string temp = t.substr(0, 2);
        for (int i = 2; i < t.size(); i += 2) {
            string d = t.substr(i, 2);
            if (d != temp && d[0] != temp[0] && d[1] != temp[1]) {
                return false;
            }
            temp = d;
        }
        return true;
    };

    for (int i = 0; i < n; i++) {
        if (s[i] == 'T') {
            if (!check(t)) {
                cout << "NO\n";
                return;
            }
            t = "";
            continue;
        }
        t += s[i];
    }
    if (!check(t)) {
        cout << "NO\n";
        return;
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

    for (int i = 1; i <= tt; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}