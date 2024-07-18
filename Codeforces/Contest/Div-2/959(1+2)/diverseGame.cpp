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
    vector<vector<int>> a(n, vector<int> (m));
    loop(i, n)
        loop(j, m)
            cin >> a[i][j];
    
    if(n == 1 && m == 1) {
        cout << -1 << '\n';
    } else {
        if(m == 1) {
            for(int i = 0; i < n - 1; i += 2) {
                swap(a[i][0], a[i + 1][0]);
            }
            if(n % 2 == 1) {
                swap(a[n - 1][0], a[0][0]);
            }
        } else {
            loop(i, n) {
                for(int j = 0; j < m - 1; j += 2) {
                    swap(a[i][j], a[i][j + 1]);
                }
                if(m % 2 == 1) 
                    swap(a[i][0], a[i][m - 1]);
            }
        }


        loop(i, n) {
            loop(j, m) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
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
