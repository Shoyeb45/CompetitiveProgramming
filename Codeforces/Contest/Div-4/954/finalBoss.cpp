#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(),(x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

ll h, n;
vector<ll> a, c;

bool check(ll mid) {
    ll health = 0;
    loop(i, n) {
        health += a[i] * (mid / c[i]);
        // cout << "health: " << health << '\n';
    }
    // cout << "health: " << health << '\n';
    // cout << "h " << h << '\n';
    return health >= h;
}

void solve() {
    cin >> h >> n;
    a.resize(n);    
    c.resize(n);

    loop(i, n) {
        cin >> a[i];
        h -= a[i];
    }

    loop(i, n)
        cin >> c[i];
    
    ll low = 0, high = 1e11;
    ll ans = 0;

    if(h > 0) {
        while(low <= high) {
            ll mid = low + (high - low)/2;
            // cout << "High: " << high << " Low: " << low << '\n';
            // cout << "mid : " << mid << '\n';
            if(check(mid)) {    
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }    
        // check(24999999999);
        cout << ans + 1 << '\n';
    } else {
        cout << 1 << '\n';
    }
    
}

int main() {
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
