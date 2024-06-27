#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

ll n, h;
vector<int> a;

bool check(ll mid) {
    ll points = mid * n;
    for(int i = 0; i < n - 1; i++) {
        ll r = (a[i] + mid) - a[i + 1];
        if(r > 0) {
            points -= r;
        }
    }
    return points >= h;
}

void solve() {
    cin >> n >> h;
    a.resize(n);
    loop(i, n)
        cin >> a[i];
    ll low = 0, high = 1e18;
    ll ans = 0;
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << '\n';
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
