#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
ll x;
vector<ll> a;

bool f(ll mid, ll mxHeight, ll mxW) {
    if(mid >= mxHeight) {
        if(mxW > x) {
            return false;
        }
        mxW += (mid - mxHeight) * 1LL * n;

        return mxW <= x;
    }

    mxW = 0;
    for(auto x: a) {
        if(mid >= x) {
            mxW += (mid - x);
        }
    }
    return mxW <= x;
}

void solve() {
    cin >> n >> x;
    a.resize(n);

    for(auto &x: a) {
        cin >> x;
    }
    ll mx = *max_element(range(a)), mxW = 0;

    for(auto x: a) {
        mxW += (mx - x);
    }
    ll low = 0, high = 1e12;
    ll ans = 0;

    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(f(mid, mx, mxW)) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
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