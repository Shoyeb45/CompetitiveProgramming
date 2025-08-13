#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    queue<pair<int, int>> q;

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> m_distance(n, vector<int> (m, INT_MAX));
    queue<pair<int, pair<int, int>>> qu;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'M') {
                q.push({i, j});
                m_distance[i][j] = 0;
                vis[i][j] = true;
            } else if (a[i][j] == 'A') {
                qu.push({0, {i, j}});
            }
        }
    }

    vector<vector<int>> indices = {
        {0, 1, 'R'},
        {1, 0, 'D'},
        {-1, 0, 'U'},
        {0, -1, 'L'}
    };

    while (!q.empty()) {
        auto idx = q.front();
        q.pop();

        for (auto dx: indices) {
            int nx = idx.first + dx[0], ny = idx.second + dx[1];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] != '#' && !vis[nx][ny]) {
                vis[nx][ny] = true;
                q.push({nx, ny});

                m_distance[nx][ny] = min(m_distance[nx][ny], m_distance[idx.first][idx.second] + 1);
            }
        }
    }

    for (auto &x: vis) {
        fill(x.begin(), x.end(), false);
    }

    vector<vector<char>> path(n, vector<char> (m, '0'));
    
    auto is_edge_index = [&](int i, int j) -> bool {
        return i == 0 || j == 0 || i == n - 1 || j == m - 1;  
    };

    while (!qu.empty()) {
        int dist = qu.front().first;
        auto idx = qu.front().second;
        if (is_edge_index(idx.first, idx.second)) {
            cout << "YES\n" << dist << "\n";
            string ans = "";
            pair<int, int> p = {idx.first, idx.second};
            for (int i = 0; i < dist; i++) {
                ans += path[p.first][p.second];
                // cout << p.first << " " << p.second << "\n";
                if (path[p.first][p.second] == 'U') {
                    p.first += 1; 
                } else if (path[p.first][p.second] == 'D') {
                    p.first -= 1; 
                } else if (path[p.first][p.second] == 'L') {
                    p.second += 1;
                } else {
                    p.second -= 1;
                }
            
            }
            reverse(ans.begin(), ans.end());
            cout << ans << "\n";
            return;
        }
        qu.pop();


        for (auto dx: indices) {
            int nx = idx.first + dx[0], ny = idx.second + dx[1];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] == '.' && dist + 1 < m_distance[nx][ny] && !vis[nx][ny]) {
                vis[nx][ny] = true;
                qu.push({ dist + 1, { nx, ny } });
                path[nx][ny] = (char) dx[2];

                


            }
        }
    }

    cout << "NO\n";

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

    while (tt--) {
        solve();
    }

    return 0;
}