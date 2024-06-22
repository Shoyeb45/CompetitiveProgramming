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


int n, k;
vector<int> a;

bool check(ll mid) {
    ll steps = 0;
    for(int i = n/2; i < n; i++) {
        if(mid - a[i] > 0) {
            steps += mid - a[i];
        }
        if(steps > k) 
            return false;
    }
    // cout << steps << '\n';
    return steps <= k;
}
void solve() {
    cin >> n >> k;
    a.resize(n);
    loop(i, n) 
        cin >> a[i];
    sort(range(a));

    ll low = 0, high = 1e13;
    ll ans = a[n/2];

    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    // cout << check(429496729605) << '\n';
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
