#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(n, vector<int> (3, 0));
    loop(i, n) {
        loop(i, 3) {
            cin >> a[i];
        }
    }

    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
