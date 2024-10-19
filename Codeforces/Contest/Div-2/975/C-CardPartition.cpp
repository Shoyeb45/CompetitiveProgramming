#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
ll k;
vector<ll> a;
void solve() {
    cin >> n >> k;
    a.resize(n);
    ll mx = INT_MIN, sum = 0;
    for(auto &x: a) {
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }

    for(int s = n; s >= 1; s--) {
        ll y = (sum + k);
        ll biggMul = y - (y % s);
        ll d = biggMul / s;
        if(biggMul >= sum && d >= mx) {
            cout << s << "\n";
            return;
        }
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