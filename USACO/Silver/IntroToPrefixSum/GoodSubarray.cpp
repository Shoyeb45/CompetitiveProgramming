#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
void solve() {
    string s;
    cin >> n >> s;
    vector<ll> pref(n + 1, 0);
    unordered_map<ll, int> mp;
    
    mp[0] = 1;
    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        pref[i] += (pref[i - 1] + s[i - 1] - '0');  // Build prefix sum
        ans += mp[pref[i] - i];                     // Find 
        mp[pref[i] - i]++;                          // insert in map
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
