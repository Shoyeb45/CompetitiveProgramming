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
    vector a(n, vector<int> (n));
    int st = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = st++;
        }
    }

    debug(a);
    ll ans = LLONG_MIN;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll temp = a[i][j];
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    temp += a[nx][ny];
                }
            }
            ans = max(ans, temp);
        }
    }

    cout << ans << '\n';
}   



int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/in.txt", "r", stdin);
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/out.txt", "w", stdout);
        freopen("/home/shoyeb45/Codes/CompetitiveProgramming/stdin-stdout-stderr/err.txt", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}