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

int mod_sum(int x, int y, int m) {
    return ((x + y) % m + m) % m;
}


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct node {
    int i;
    int j;
    int time;  
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    queue<node> q;
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') {
                q.push({i, j, 0});
            }
        }
    }
    // Ghost time
    vector<vector<int>> g_t(n, vector<int> (m, INT_MAX));

    auto fill_gt = [&](int r, int c, char ch) -> void {
        int i = r, j = c;
        g_t[i][j] = 0;
        int t = 1;
        debug(r, c);
        if (ch == 'L') {
            j = mod_sum(j, -1, m);
            while (j != c) {
                g_t[i][j] = min(g_t[i][j], t++);
                debug(i, j);
                j = mod_sum(j, -1, m);
            } 
        } else if (ch == 'R') {
            j = mod_sum(j, 1, m);
            while (j != c) {
                g_t[i][j] = min(g_t[i][j], t++);
                j = mod_sum(j, 1, m);
            }
        } else if (ch == 'U') {
            i = mod_sum(i, -1, m);
            while (i != r) {
                g_t[i][j] = min(g_t[i][j], t++);
                i = mod_sum(i, -1, n);
            }
        } else {
            i = mod_sum(i, 1, m);
            while (i != r) {
                g_t[i][j] = min(g_t[i][j], t++);
                i = mod_sum(i, 1, n);
            }
        }
    };


    for (int  i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        char ch;
        cin >> ch;
        fill_gt(r, c, ch);
    }
    
    
    while (!q.empty()) {
        int x = q.front().i, y = q.front().j, time = q.front().time;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            bool is_valid_index = nx >= 0 && ny >= 0 && nx < n && ny < m;

            if (is_valid_index && !vis[nx][ny]) {
                if (a[nx][ny] == '.') {
                    
                    if (g_t[nx][ny] == INT_MAX) {
                        q.push({nx, ny, time + 1});
                        vis[nx][ny] = true;
                        continue;
                    } 
                    int temp_t = t + 1;
                    if (temp_t % n == g_t[nx][ny] || temp_t % m == g_t)
                } else if (a[nx][ny] == 'E') {
                    cout << time + 1 << "\n";
                    return;
                }
            } 
        }
    }
    cout << -1 << "\n";
    string s;
    cin >> s;
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