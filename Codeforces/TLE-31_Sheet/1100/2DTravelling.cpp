#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, k, a, b;
void solve() {
    cin >> n >> k >> a >> b;
    a--, b--;
    vector<pair<ll, ll>> vp(n);
    for(auto &it: vp) {
        cin >> it.first >> it.second;
    }

    if(k == 0) {
        cout << (ll)(1LL * llabs(vp[a].first - vp[b].first) + 1LL * llabs(vp[a].second - vp[b].second)) << "\n";
        return;
    }  

    ll ans = (ll)(llabs(vp[a].first - vp[b].first) + llabs(vp[b].second - vp[a].second));
    ll distA = INT64_MAX / 2;
    ll distB = INT64_MAX / 2;

    for(int i = 0; i < k; i++) {
        distA = min(distA, (ll)(1LL * llabs(vp[i].first - vp[a].first) + 1LL * llabs(vp[i].second - vp[a].second)));
        distB = min(distB, (ll)(1LL * llabs(vp[i].first - vp[b].first) + 1LL * llabs(vp[i].second - vp[b].second)));
    }

    ans = min(ans, distA + distB);
    cout << ans << "\n";
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