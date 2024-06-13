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
ll x, y, z, k;
void solve() {
    cin >> x >> y >> z >> k;
    ll ans = 0;
    
    loop(i, x) {
        loop(j, y) {
            ll l = i + 1, b = j + 1;
            ll c = k / (l * b);
            if(k % (l * b) == 0 && c <= z) {
                ans = max(ans, (x - l + 1) * (y - b + 1) * (z - c + 1));
            } 
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
