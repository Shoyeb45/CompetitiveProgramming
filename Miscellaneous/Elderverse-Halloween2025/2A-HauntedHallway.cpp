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
    int n, m;
    cin >> n >> m;
    vector<char> a(n);
    while (m--) {
        string s;
        cin >> s;
        int idx = stoi(s.substr(0, s.size() - 1));
        a[idx] = s.back();
    }
    int left = count(range(a), 'L'), right = count(range(a), 'R');
    if (left == 0 || right == 0) {
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

    for (int i = 1;i <= tt; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}