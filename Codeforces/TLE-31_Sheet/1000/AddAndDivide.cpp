#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;


ll a, b;

ll moves(ll a, ll b) {
    ll ans = 0;

    while(a > 0) {
        a /= b;
        ans++;
    }

    return ans;
}

void solve() {
    cin >> a >> b;

    ll ans = INT_MAX;

    for(int i = 0; i <= 6; i++) {
        if(b == 1 && i == 0) {
            continue;
        }
        ll x = moves(a, b + i);
        ans = min(ans , x + i);
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