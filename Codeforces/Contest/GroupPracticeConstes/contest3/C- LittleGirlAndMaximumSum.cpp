#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, q;
void solve() {
    cin >> n >> q;
    vector<ll> a(n);
    for(auto &x: a) {
        cin >> x;
    }
    vector<ll> pref(n + 2, 0);

    while(q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        pref[a]++;
        pref[b + 1]--;
    }

    for(int i = 1; i <= n; i++) {
        pref[i] += pref[i - 1];
    }

    sort(range(a));
    sort(range(pref));
    reverse(range(a));
    reverse(range(pref));
    

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += a[i] * pref[i];
    }
    cout << ans << "\n";
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
