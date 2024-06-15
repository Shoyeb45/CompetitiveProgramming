#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

ll k, n;
vector<ll> a;
bool check(ll mid) {
    ll cnt = 1;
    ll current = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] - current >= mid) {
            current = a[i];
            cnt++;
        }
    }
    return cnt >= k;
}

void solve() {
    cin >> n >> k;
    a.resize(n);

    loop(i, n)
        cin >> a[i];
    
    ll low = 0, high = 1e13, ans = -1;
    while(low <= high) {
        ll mid = low + (high - low) / 2;
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
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
