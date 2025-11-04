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
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++) {
        int p, h, w;
        cin >> p >> h >> w;
        vp[i] = {p, h * w};
    }   
    sort(range(vp));
    int max_area = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vp[i].first + vp[j].first <= d && vp[i].second + vp[j].second > max_area) {
                max_area = vp[i].second + vp[j].second;
            }
        }
    }
    cout << fixed << setprecision(6) << M_PI * (double) max_area / 4 << "\n";
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