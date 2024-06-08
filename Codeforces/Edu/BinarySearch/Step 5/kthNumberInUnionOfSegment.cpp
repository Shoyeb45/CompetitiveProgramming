#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

ll cnt(vector<pair<ll, ll>> &vp, ll mid) {
    ll count = 0;
    loop(i, vp.size()) {
        if(vp[i].first > mid) {
            count += 0;
        } else {
            count += min(mid - vp[i].first, vp[i].second - vp[i].first + 1);
        }
    }
    return count;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> vp;

    loop(i, n) {
        int x, y;
        cin >> x >> y;
        vp.push_back({x, y});
    }

    ll ans = -1, low = INT_MIN, high = INT_MAX;
    while(low <= high) {
        ll mid = low + (high - low)/2;
        if(cnt(vp, mid) <= k) {
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
