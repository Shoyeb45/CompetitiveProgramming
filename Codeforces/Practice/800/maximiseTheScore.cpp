#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
void solve() {
    cin >> n;
    vector<ll> a;
    for(int i = 0; i < 2 * n; i++) {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    sort(range(a));

    ll sum = 0;
    for(int i = 0; i < 2 * n; i += 2) {
        sum += a[i];
    }
    cout << sum << "\n";
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