#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m, k;
void solve() {
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int> (m, 0));
    for (int i = 0, u, v; i < k; i++) {
        cin >> u >> v;
        a[--u][--v] = 1;
    }

    queue<
        pair<
            pair<int, pair<int, int>>, 
            pair<int, int>
        >
    > q;
    int dx[] = {-1, 1, 0, 0}; 
    int dy[] = {0, 0, -1, 1};
    
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    auto valid_index = [&](int i, int j) -> bool {
        return i >= 0 && j >= 0 && i < n && j < m;
    };
    q.push(make_pair(make_pair(0, make_pair(-1, -1)), make_pair(0, 0)));
    vis[0][0] = true;
    while (!q.empty()) {
        auto idx = q.front().second;
        int amt = q.front().first.first;
        auto taken_idx = q.front().first.second;
        if (idx.first == n - 1 && idx.second == m - 1) {
            cout << amt << "\n";
            return;
        }
        cout << "current Index: " << idx.first + 1 << " " << idx.second + 1 << "\n";
        cout << "curr amt : " << amt << "\n";
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = idx.first + dx[k], ny = idx.second + dy[k];

            if (valid_index(nx, ny) && !vis[nx][ny]) {
                cout << "new idx: " << nx + 1 << " " << ny + 1 << "\n";

                if (a[nx][ny] || nx == taken_idx.first || ny == taken_idx.second) {
                    cout << "t\n";
                    q.push(make_pair(make_pair(amt, taken_idx), make_pair(nx, ny)));
                } else {
                    cout << "t ++1\n";
                    q.push(make_pair(make_pair(amt + 1, make_pair(nx, ny)), make_pair(nx, ny)));
                }
                vis[nx][ny] = true;
            }
        }
    }
    cout << -1 << "\n";
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