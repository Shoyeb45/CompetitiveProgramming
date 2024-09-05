#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll x, y, k;
void solve() {
    cin >> x >> y >> k;

    int xDir = (x + k - 1) / k;
    int yDir = (y + k - 1) / k;

    ll ans = 0;
    if(yDir >= xDir) {
        ans = 2 * yDir;
    } 
    else {
        ans = 2 * xDir - 1;
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
