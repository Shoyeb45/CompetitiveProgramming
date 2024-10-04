#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
vector<ll> a;

void solve() {
    cin >> n;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }

    ll _gcd = 0;

    for(int i = 0; i < n / 2; i++) {
        _gcd = __gcd(_gcd, llabs(a[i] - a[n - i - 1]));
    }

    cout << _gcd << "\n";
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