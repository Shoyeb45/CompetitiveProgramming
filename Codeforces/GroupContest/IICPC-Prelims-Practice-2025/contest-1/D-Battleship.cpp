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


void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), di(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> di[i];
    }

    vector<vector<int>> mat(11, vector<int> (11, 0));

    auto update = [&](int x, int y, int a, int b) {
        for (int i = x; i <= a; i++) {
            for (int j = y; j <= b; j++) {
                mat[i][j]++;
            }
        }
    };
    for (int i = 0; i < n; i++) {
        int d = a[i];
        int x = c[i], y = di[i];
        int l = b[i];
        if (d == 0) {
            int ny = y + l - 1;
            if (x > 10 || ny < 0 || y > 10 || ny > 10 || x < 0 || y < 0) {
                cout << "N\n";
                return;
            }
            update(x, y, x, ny);
            continue;
        } 

        int nx = x + l - 1;
        if (x > 10 || nx < 0 || y > 10 || nx > 10 || x < 0 || y < 0) {
            cout << "N\n";
            return;
        }
        update(x, y, nx, y);
    }

    for (auto &x: mat) {
        for (auto &y: x) {
            if (y >= 2) {
                cout << "N\n";
                return;
            }
        }
    }

    cout << "Y\n" << "\n";
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
