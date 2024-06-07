#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;
ll n, k;
vector<ll> a;

bool check(ll mid) {
    ll tot = 0;
    for(auto x: a) {
        tot += min(x, mid);
    }
    return tot >= k * mid;
}

void solve() {
    cin >> k >> n;
    a.resize(n);
    loop(i, n)
        cin >> a[i];
    ll low = 0, high = 1e11, ans = 0;

    while(low <= high) {
        ll mid = (low + high)/2;
        if(check(mid)) {
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
