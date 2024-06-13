#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;
ll n;
vector<ll> a;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

// Solution - 1

// void solve() {
//     cin >> n;
//     a.resize(n);
//     map<ll, ll> m;

//     loop(i, n) {
//         cin >> a[i];
//     }
    
//     ll sum = 0, ans = 0;
//     loop(i , n) {
//         m[2 * a[i]]++;
//         sum += a[i];
//         if(m.find(sum) != m.end()) {
//             ans++;
//         }
//     }
//     cout << ans << '\n';
// }

// Solution - 2

void solve() {
    cin >> n;
    ll ans = 0;
    ll mx = INT_MIN, sum = 0;
    loop(i, n) {
        ll x;
        cin >> x;

        mx = max(x, mx);
        sum += x;
        if(sum == 2 * mx) 
            ans++;
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
