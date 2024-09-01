#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll l, r;
void solve() {
    cin >> l >> r;

    ll rhs = 1LL * 2 * (r - l);
    int ans = 0;
    for(int i = 1; ; i++) {
        ll lhs = 1LL * i * (i - 1);
        if(lhs <= rhs) {
            ans = i;
        }
        else {
            break;
        }
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
