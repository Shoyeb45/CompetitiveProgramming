#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

ll n, k;
vector<ll> a;

bool check(ll mid) {
    bool chk = 1;
    ll temp_sum = 0;
    ll seg = 1;

    loop(i, n) {
        if(a[i] > mid) {
            chk = 0;
            break;
        }

        if(temp_sum + a[i] <= mid) {
            temp_sum += a[i];
        } else {
            temp_sum = a[i];
            seg++;
        }
    }

    return (chk)? (seg <= k): 0;
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    ll low = 0, high = 0;
    loop(i, n) {
        cin >> a[i];
        high += a[i];
    }    

    high += 10000;

    ll ans = 0;
    while(low <= high) {
        ll mid = low + (high - low )/ 2;
        if(check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
