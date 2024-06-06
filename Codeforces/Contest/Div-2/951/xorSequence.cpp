#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int x, y;
    cin >> x >> y;
    for(int i = 20; i <= 40; i++) {
        cout << ((i) ^ x) << "  ";
    }
    cout << '\n';
    for(int i = 20; i <= 40; i++) {
        cout << ((i) ^ y) << "  ";
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
