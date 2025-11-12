#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;
const int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
const int dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};

void solve() {
    int x, y;
    cin >> x >> y;
    vector<vector<int>> ans(9, vector<int> (9, -1));

    ans[x][y] = 1;

    auto valid_idx = [&](int nx, int ny) -> bool {
        return nx >= 1 && ny >= 1 && nx <= 8 && ny <= 8;
    };

    vector<vector<int>> freq(9, vector<int>(9, 0));
    
    auto find_freq = [&](int i, int j) -> int {
        int f = 0;
        for (int k = 0; k < 8; k++) {
            int ni = dx[k] + i, nj = dy[k] + j;
            if (valid_idx(ni, nj) && ans[ni][nj] == -1) {
                f++;
            }
        }
        return f;
    };

    int d = 2;

    while (d <= 64) {
        vector<pair<int, pair<int, int>>> candidates;
        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (valid_idx(nx, ny) && ans[nx][ny] == -1) {
                int f = find_freq(nx, ny);
                candidates.push_back({f, {nx, ny}});
            }
        }

        if (candidates.empty()) break; // stuck

        sort(candidates.begin(), candidates.end()); // pick min degree

        // choose best move
        x = candidates[0].second.first;
        y = candidates[0].second.second;
        ans[x][y] = d++;
    }


    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
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