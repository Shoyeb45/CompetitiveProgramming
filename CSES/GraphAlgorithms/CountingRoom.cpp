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

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<bool>> v(n, vector<bool> (m, false));
    
    vector<pair<int, int>> idxs = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    auto bfs = [&](int i, int j) -> void {
        queue<pair<int, int>> q;
        q.push({i, j});
        v[i][j] = true;

        while (!q.empty()) {
            auto idx = q.front();
    
            for (auto ind: idxs) {
                int nx = idx.first + ind.first, ny = idx.second + ind.second;

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] == '.' && !v[nx][ny]) {
                    q.push({nx, ny});
                    v[nx][ny] = true;
                }    
            }    
            q.pop();
        }    
    };    

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.' && !v[i][j]) {
                bfs(i, j);
                ans++;
            }
        }
    }

    cout << ans << "\n";
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