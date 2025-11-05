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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x: a) {
        cin >> x;
    }   
    for (int &x: b) {
        cin >> x;
    }   

    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++) {
        vp.push_back({a[i] - b[i], i + 1});
    }
    sort(rrange(vp));
    vector<int> ans = {vp[0].second};

    for (int i = 1; i < n; i++) {
        if (vp[i].first != vp[0].first) {
            break;
        } else {
            ans.push_back(vp[i].second);
        }
    }
    sort(range(ans));
    cout << ans.size() << "\n";
    for (auto x: ans) {
        cout << x << " ";
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
    tt = 1;
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}