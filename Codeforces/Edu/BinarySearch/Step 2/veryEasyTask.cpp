#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool check(ll mid, ll x, ll y, ll n) {
    // if(mid < min(x, y))
    //     return false;
    // ll time = mid - min(x, y);
    // ll cnt = 1;
    // ll rem = 0;
    // while(time >= max(x, y)) {
    //     cnt += (1 + max(x, y)/min(x, y));
    //     time -= max(x, y);
    //     rem += (max(x, y) % min(x, y));
    // }

    // cnt += (rem/min(x, y));
    // cnt += (time/min(x, y));
    // return cnt >= n;
    ll t1 = mid/x, t2 = mid/y;
    return (1 + t1 + t2) >= n;
}
void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    ll low = 0, high = 2e9;
    ll ans = 1;
    while(low <= high) {
        ll mid = low + (high - low)/2;
        if(check(mid, x, y, n)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans + min(x, y) << '\n';
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
