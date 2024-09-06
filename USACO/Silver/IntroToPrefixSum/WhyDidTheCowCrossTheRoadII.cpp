#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, k, b;
void solve() {
    cin >> n >> k >> b;
    vector<bool> isDamaged(n + 1, false);
    vector<ll> pref(n + 1, 0);

    for(int i = 0; i < b; i++) {
        int x;
        cin >> x;
        isDamaged[x] = true;
    } 

    for(int i = 1; i <= n; i++) {
        pref[i] += pref[i - 1] + (int)isDamaged[i];
    }


    ll ans = b;
    for(int i = k + 1; i <= n; i++) {
        // cout << "indices: " << i << " " << i - k << "\n";
        ans = min(ans, pref[i] - pref[i - k]);
    }
    cout << ans << "\n";
}

int main() {
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
