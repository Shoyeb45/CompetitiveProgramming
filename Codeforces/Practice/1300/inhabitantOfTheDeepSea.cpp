#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    loop(i, n)  
        cin >> a[i];
    
    ll l = 0, r = n - 1;
    while(l <= r && k) {
        if(l == r) {
            if(k >= a[l]) {
                a[l] = 0;
                k = 0;
            } else {
                a[l] -= k;
                k = 0;
            }
            break;
        }

        ll m = min(a[l], a[r]);

        if(k >= 2 * m) {
            a[l] -= m;
            a[r] -= m;
            k -= (2 * m);
        } else {
            a[r] -= (k/2);
            if(k % 2) 
                a[l] -= (k/2 + 1);
            else 
                a[l] -= k/2;
            k = 0;
        }

        if(!a[l])
            l++;
        else if(!a[r])
            r--;
    }

    int ans = 0;
    for(auto x: a) 
        ans += (x == 0);
        
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
