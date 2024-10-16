#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, k, d, w;
vector<ll> t;

void solve() {
    cin >> n >> k >> d >> w;
    t.resize(n);

    for(auto &x: t) {
        cin >> x;
    }
    
    ll prev = t[0] + w;
    int i = 1;
    ll ans = 0;
    int num = 1;
    while(i < n) {
        while(i < n && num <= k) {
            if(!(t[i] >= prev && t[i] <= prev + d)) {
                break;
            }
            prev = t[i] + w;
            i++, num++;
        }
        ans++;
        i++;
        prev = t[i] + w;
        num = 1;
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