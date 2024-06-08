#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

ll n, k;
vector<ll> a;
vector<ll> b;

ll less_than(vector<ll> &b, ll target) {
    int low = 0, high = b.size() - 1;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high)/2;
        if(b[mid] < target) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    } 

    return ans + 1;
}

ll cnt(ll mid) {
    ll count = 0;

    loop(i, a.size()) {
        count += less_than(b, mid - a[i]);
    }

    return count;
}

void solve() {
    cin >> n >> k;

    a.resize(n);
    b.resize(n);

    loop(i, n)
        cin >> a[i];
    loop(i, n)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll low = 1, high = 1e13, ans = -1;

    while(low <= high) {
        ll mid = low + (high - low)/2;
        if(cnt(mid) < k) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
