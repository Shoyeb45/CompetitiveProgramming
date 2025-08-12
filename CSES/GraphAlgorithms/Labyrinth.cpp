#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m;
void solve() {
    cin >> n >> m;
    vector<string> a(n);

    // cout << "hi" <<"\n";

    queue<
        pair<int, pair<int, int>>
     > q;

    vector<vector<bool>> vis(n, vector<bool> (m, false));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'A') {
                q.push({1, {i, j}});
                vis[i][j] = true;
                break;
            }
        } 
    }
    
    vector<vector<char>> path(n, vector<char> (m, '0'));

    vector<vector<int>> d = {
        {1,  0, 'D'},
        {0,  1, 'R'},
        {-1, 0, 'U'},
        {0, -1, 'L'}
    };

    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        for (auto dire: d) {
            int nx = x.second.first + dire[0], ny = x.second.second + dire[1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] == '.' && !vis[nx][ny]) {
                vis[nx][ny] = true;
                int d = x.first + 1;
                q.push({d, {nx, ny}});
                path[nx][ny] = dire[2];
            } else if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] == 'B') {
                cout << "YES\n";
                cout << x.first << "\n";
                string ans = "";
                path[nx][ny] = dire[2];

                pair<int, int> p = {nx, ny};
                for (int i = 0; i < x.first; i++) {
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