#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, k;
vector<ll> a;
void solve() {
    cin >> n >> k;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }
    ll mx = *max_element(range(a));    
    ll mn = *min_element(range(a));    

    if(mx - mn == k) {
        cout << -1 << '\n';
        return;
    }

    for(auto &x: a) {
        ll ans = x;
        ll low = 0, high = 1e13;
        
        while(low <= high) {
            ll mid = low + (high - low) / 2;
            ll rem = 2 * k * mid;

            if(rem + x >= mx) {
                ans = rem;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        } 
        // cout << ans << "\n";
        if(abs(x + ans - mx) < abs(x - mx)) {
            if(abs(x + ans - mx) < abs((x + ans - 2 * k) - mx)) {
                x += ans;
            }
            else {
                x += ans;
                x -= 2 * k;
            }
        }
    }


    // for(auto x: a) {
    //     cout << x << ' ';
    // }
    // cout << endl;
    mx = *max_element(range(a));
    mn = *min_element(range(a));

    if(mx - mn < k) {
        cout << mx << '\n';
    }
    else {
        cout << -1 << "\n";
    }
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}