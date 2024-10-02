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
    for(auto &X: a) {
        cin >> X;
    }
    int K = k;
    sort(range(a));

    vector<ll> pref(n + 1);

    for(int i = 1; i <= n; i++) {
        pref[i] += pref[i - 1] + a[i - 1];
    }

    ll ans = 0;
    for(int ope = 0; ope <= k; ope++) {
        ans = max(ans, (pref[n - (k - ope)] - pref[2 * ope]));
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