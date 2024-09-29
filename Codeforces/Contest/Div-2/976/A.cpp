#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

ll n, k;
ll logKN(ll n, ll k) {
    ll ans = 0;
    while(n > 0) {
        ans++;
        n /= k;
    } 
    return ans - 1;
}

ll power(ll x, ll y) {
    ll temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return 1LL * temp * 1LL * temp;
    else
        return 1LL * x * 1LL *  temp * 1LL* temp;
}

void solve() {
    cin >> n >> k;

    if(k == 1) {
        cout << n << '\n';
    }
    else if(n < k) {
        cout << n << "\n";
    }
    else {
        ll x;
        ll pw;
        ll ans = 0;
        while(n >= k) {
            x = logKN(n, k);
            pw = power(k, x);
            
            ans += (n / pw);
            n = max(n - pw * 1LL *  (n / pw), 0LL);
        }

        cout << (n) + ans << "\n";
    }
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