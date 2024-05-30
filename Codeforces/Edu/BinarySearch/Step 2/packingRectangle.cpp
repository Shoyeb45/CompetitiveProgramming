#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

bool is_fit(ll a, ll b, ll x, ll n) {
    return (x/a) * (x/b) >= n;
}

ll min_side(ll a, ll b, ll n) {
    ll low = 0, high = INT_MAX;

    // while(!is_fit(a, b, high, n)) {
    //     high *= 2;
    // }

    // while(low + 1 < high) {
    //     ll x = low + (high - low)/2;
    //     if(is_fit(a, b, x, n)) {
    //         high = x;
    //     } else {
    //         low = x;
    //     }
    // }
    ll ans = 0;
    while(low + 1 < high) {
        ll x = (high + low)/2;
        if(is_fit(a, b, x, n)) {
            ans = x;
            high = x - 1;
        } else {
            low = x + 1;
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, n;
    cin >> a >> b >> n;
    
    cout << min_side(a, b, n) << '\n';
    return 0;
}
