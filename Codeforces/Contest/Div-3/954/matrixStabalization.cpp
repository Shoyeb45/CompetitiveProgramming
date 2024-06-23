#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    loop(i, n)
        loop(j, m)
            cin >> a[i][j];
    
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, -1, 0, 1};
    loop(i, n) {
        loop(j, m) {
            int mx = INT_MIN;
            loop(k, 4) {
                int x = i + dx[k];
                int y = j + dy[k];
                if((x >= 0 && x < n) && (y >= 0 && y < m)) {
                    mx = max(mx, a[x][y]);
                }
            }
            a[i][j] = min(a[i][j], mx);
        }
    }

    loop(i, n) {
        loop(j, m) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
