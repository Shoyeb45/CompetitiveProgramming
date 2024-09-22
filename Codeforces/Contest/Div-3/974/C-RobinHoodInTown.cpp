#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
vector<ll> a;
void solve() {
    cin >> n;
    a.resize(n);

    ll sum = 0;
    for(auto &x: a) {
        cin >> x;
        sum += x;
    }

    if(n == 1 || n == 2) {
        cout << "-1" << "\n";
        return;
    }
    sort(range(a));
    ll ans = a[n / 2] * 2 * n * 1LL - sum  + 1;
    if(ans <= 0) {
        cout << 0 << '\n';
        return;
    }
    cout << ans << "\n";

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
