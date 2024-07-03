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

ll x, y;
ll n;

void solve() {
    cin >> x >> y;
    cin >> n;
    vector<ll> f = {x, y, y - x, -x, -y, -(y - x)};
    
    int idx = (n % 6 == 0)? 5: (n % 6) - 1;
    cout << (f[idx] % mod + mod) % mod << '\n';
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
