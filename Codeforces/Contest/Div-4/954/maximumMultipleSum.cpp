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

void solve() {
    ll n;   
    cin >> n;

    ll ans = 0, sum = INT_MIN;
    for(int x = 2; x <= n; x++) {
        ll k = n/x;
        if(((k)*(k + 1)/2) * x >= sum) {
            sum = ((k)*(k + 1)/2) * x;
            ans = x;
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
