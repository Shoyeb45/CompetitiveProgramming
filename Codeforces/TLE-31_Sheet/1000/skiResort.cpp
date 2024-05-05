#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    loop(i, n)  cin >> a[i];

    int i = 0;
    ll ans = 0;
    while(i < n) {
        int cnt = 0;
        if(a[i] <= q) {
            while(i < n && a[i] <= q) {
                cnt++;
                i++;
            }
            if(cnt >= k) {
                // ll a = 1LL * (cnt - k + 1) * 1LL * (cnt + 1);
                // ll b = (cnt * (cnt + 1))/2 - (k * (k - 1))/2;
                // ans = ans + (a - b);
                ans += 1LL*(cnt - k + 1) * 1LL * (cnt - k + 2)/2;
            }
        } else {
            i++;
        }

    }
    cout << ans << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();   
    }
    
    return 0;
}
