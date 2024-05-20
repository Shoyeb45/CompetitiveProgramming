#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

ll lowerbound(ll n, int target) {
    ll l = 1, r = 1e6;
    ll ans = 0;
    while(l <= r) {
        ll mid = (l + r)/2;
        ll x = 1LL * mid * n;
        if(x >= target) {
            ans = x;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    loop(i, n)
        cin >> a[i];
    
    int ans = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] >= ans + 1) 
            ans = a[i];
        else {
            ans = lowerbound(a[i], ans + 1);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}
