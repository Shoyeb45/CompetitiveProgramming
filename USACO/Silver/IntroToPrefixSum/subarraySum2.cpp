#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll n, k;
void solve() {
    cin >> n >> k;

    ll prefSum = 0;
    ll ans = 0;

    map<ll, ll> mp;
    mp[0]++;
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        prefSum += x;
        ll req = prefSum - k;
        
        ans += mp[req]; 

        mp[prefSum]++;
    }

    cout << ans << "\n";
}

int main() {
    NFS
    int tt;
    tt = 1;

    while (tt--) {
        solve();
    }
    
    return 0;
}

