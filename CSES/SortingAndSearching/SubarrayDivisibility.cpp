#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll mp[(int)(2e5 + 1)];
int n;
vector<int> a;

void solve() {
    cin >> n;
    a.resize(n);

    ll pref = 0, ans = 0;
    mp[0] = 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pref += a[i];
        ll rem = ((pref % n) + n) % n;
        ans += mp[rem];
        
        mp[rem]++;
    }

    cout << ans << "\n";
}

int main() {
    NFS
    int tt;
    tt = 1;

    while (tt--) {
        solve();
    }
    
    return 0;
}
