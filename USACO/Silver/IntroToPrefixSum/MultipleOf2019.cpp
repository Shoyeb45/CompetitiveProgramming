#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 2019;

string s;
void solve() {
    cin >> s;
    int n = s.size();
    
    int powerOfTen = 1, suffix = 0;

    vector<int> mp(mod);
    mp[0] = 1;
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        suffix = (suffix + (s[i] - '0') * powerOfTen) % mod;
        powerOfTen = (powerOfTen * 10) % mod; 
        ans += mp[suffix];
        mp[suffix]++;
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
