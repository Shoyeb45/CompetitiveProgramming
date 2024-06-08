#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;
ll n, k;

ll cnt(ll mid) {
    ll count = 0;
    for(int i = 1; i <= n; i++) {
        ll mini = (mid % i == 0)? (mid/i) - 1: (mid/i);
        count += min(mini, n);
    }
    return count;
}

void solve() {
    cin >> n >> k;

    ll low = 1, high = 1e13;
    ll ans = -1;
    while(low <= high) {
        ll mid = low + (high - low)/2;
        if(cnt(mid) < k) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }    

    cout << ans << '\n';
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
