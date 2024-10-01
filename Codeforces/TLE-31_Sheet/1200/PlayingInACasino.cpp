#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, m;
void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));

    for(auto &x: a) {
        for(auto &y: x) {
            cin >> y;
        }
    }
    
     for (int col = 0; col < m; ++col) {
        vector<int> column;
        for (int row = 0; row < n; ++row) {
            column.push_back(a[row][col]);
        }

        sort(column.begin(), column.end(), greater<int>());

        for (int row = 0; row < n; ++row) {
            a[row][col] = column[row];
        }
    }

   ll ans = 0;

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {
            ans += 1LL * (n - 2 * i - 1) * a[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        ans -= 1LL * (n - 1) * a[n - 1][i];
    }

    cout << ans << '\n';
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}