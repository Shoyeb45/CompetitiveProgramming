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

    for(auto &x: a) {
        cin >> x;
    }

    vector<ll> div;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            if(i == n / i) {
                div.push_back(i);
            }
            else {
                div.push_back(i);
                div.push_back(n / i);
            }
        }
    }

    ll mxx = *max_element(range(a)), mnn = *min_element(range(a));
    if(div.empty()) {
        cout << (ll)(mxx - mnn) << '\n';
    }
    else {
        vector<ll> pref(n + 1);

        ll ans = mxx - mnn;

        for(int i = 1; i <= n; i++) {
            pref[i] += a[i - 1] + pref[i - 1];
        }

 
        for(auto x: div) {
            ll mn = INT64_MAX, mx = INT64_MIN;
            for(int i = 0; i + x <= n; i += x) {
                mn = min(mn, pref[i + x] - pref[i]);
                mx = max(mx, pref[i + x] - pref[i]);
            }
            ans = max(ans, mx - mn);
        }
        cout << ans << "\n";
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