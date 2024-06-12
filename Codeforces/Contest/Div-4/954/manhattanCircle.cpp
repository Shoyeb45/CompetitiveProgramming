#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;
int n, m;
auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

void solve() {
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m, 0));
    loop(i, n)
        loop(j, m)
            cin >> a[i][j];

    int col_ind = 1;
    loop(i, n) {
        bool check = 0;
        loop(j, m) {
            if(a[i][j] == '#') {
                col_ind += j;
                check = 1;
                break;
            }
        }
        if(check)
            break;
    }

    int mx = INT_MIN, row_ind = 0;
    loop(i, n) {
        int cnt = 0;
        loop(j, m) {
            cnt += (a[i][j] == '#');
        }
        if(cnt >= mx) {
            mx = cnt;
            row_ind = i + 1;
        }
    }

    cout << row_ind << " " << col_ind << '\n';
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
