#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll k;
ll arr[(int)(1e6)];

void solve() {
    cin >> k;
    ll low = 0, high = 2e9;

    ll ans = 0, n = 0;
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        ll sq = 1LL * mid * mid;
        if((sq - mid) >= k) {
            ans = sq;
            n = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    ll rem = ans - n - k;    
    cout << ans - rem - 1 << "\n";
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