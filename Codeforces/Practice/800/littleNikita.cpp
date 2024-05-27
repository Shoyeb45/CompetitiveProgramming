#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;

    if(n < m) {
        cout << "NO\n";
    } else if(n == m) {
        cout << "YES\n";
    } else {
        if((n - m) % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}
