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

    ll gold = 0;
    ll ans = 0;

    for(auto x: a) {
        if(x == 0) {
            if(gold != 0) {
                gold--;
                ans++;
            }
        }
        else if(x >= k) {
            gold += x;
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
