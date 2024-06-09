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


ll n, k;
vector<ll> a;

void solve() {
    cin >> n >> k;
    a.resize(n);

    ll ans = 0;
    loop(i, n) {
        cin >> a[i];
        ans += (a[i] % k == 0);
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
