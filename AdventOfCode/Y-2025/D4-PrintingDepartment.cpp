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

int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, 1, -1};

int find_number_of_rolls(vector<string> &a) {
    int n = a.size(), m = a[0].size();
    int ans = 0;
    vector<pair<int, int>> idxs;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '@') {
                int cnt = 0;
                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k], ny = j + dy[k];
    
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] == '@') {
                        cnt++;
                    } 
                }
                if (cnt < 4) {
                    ans++;
                    idxs.push_back({i, j});
                }
            }
        }
    }

    for (auto x: idxs)
        a[x.first][x.second] = '.';

    return ans;
}


void solve() {
    string s;
    vector<string> a;
    while (cin >> s) {
        a.push_back(s);
    }


    ll ans = 0;

    while (true) {
        ll x = find_number_of_rolls(a);
        if (x == 0) break;
        ans += x;
    }

    
    cout << ans << "\n";
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
    // cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}