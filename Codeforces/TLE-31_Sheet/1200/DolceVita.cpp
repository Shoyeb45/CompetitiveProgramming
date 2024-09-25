#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll n, k;
vector<ll> a;
void solve() {
    cin >> n >> k;
    a.resize(n);


    for(auto &x: a) {
        cin >> x;
    }

    sort(range(a));

    

    ll ans = 0, d = 0;

    for(int i = 0; i < n; i++) {
        d += a[i];
        
        if(d <= k) {
            ans += (k - d) / (i + 1) + 1;
        }
        else {
            break;
        }
    }
    cout << ans << '\n';
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