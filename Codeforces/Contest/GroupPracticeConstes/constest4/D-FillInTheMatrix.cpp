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

    int maxMex = 0;

    if(n == m && n == 1) {
        maxMex = 0;
    }
    else if(n == 1) {
        maxMex = 2;
        for(int i = 0; i < m; i++) {
            a[0][i] = i;
        }
    }
    else if(m == 1) {
        maxMex = 0;
        for(int i = 0; i < n; i++) {
            a[i][0] = 0;
        }
    }
    else if(n < m) {
        maxMex = n + 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a[i][j] = (i + j) % m;
            }
        }
    }
    else {
        maxMex = m;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
               a[i][j] = ((i) % (m - 1) + j) % m;
            }
        }
    }

    cout << maxMex << "\n";

    for(auto x: a) {
        for(auto y: x) {
            cout << y << " ";
        }
        cout << "\n";
    }
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