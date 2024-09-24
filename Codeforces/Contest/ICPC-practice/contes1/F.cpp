#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll n;
void solve() {
    cin >> n;
    vector<ll> a = {0, 1};
    for(int i = 2; i <= n; i++) {
        a.push_back( ( (i) * (a[i - 1] % mod + a[i - 2]  %  mod)) % mod);
    }
    // for(auto x: a) {
    //     cout << x << ' ';
    // }
    // cout << endl;
    cout << a[a.size() - 2] << "\n";
}

int main() {
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
