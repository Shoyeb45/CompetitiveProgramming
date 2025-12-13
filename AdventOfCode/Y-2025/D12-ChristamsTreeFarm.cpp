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

    vector<int> shp;
    int ans = 0;
    while (cin >> s) {
        int i = s.find(':');
        if (s.find(':') != -1) {
            int idx = s.find('x');
            if (idx == -1) {
                int cnt = 0;
                for (int i = 0; i < 3; i++) {
                    cin >> s;
                    for (auto x: s) cnt += (x == '#');
                }
                shp.push_back(cnt);
            } else {
                int n = stoi(s.substr(0, idx));
                int m = stoi(s.substr(idx + 1, i - idx - 1));
                int area = 0;
                int total_area = n * m;

                int x;
                for (int i = 0; i < 6; i++) {
                    cin >> x;
                    cout << x <<" ";
                    total_area -= x * shp[i];
                }
                cout << "\n";
                debug(n, m, area, total_area);
                ans += (total_area > 0);
            }
        }
    }
    debug(shp);
    cout << ans << "\n";
}   



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/Users/keerthi/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif
    int tt;
    tt = 1;
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}