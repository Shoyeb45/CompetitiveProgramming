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

    ll ans = 0;
    ll temp = INT_MIN;

    for(int i = 0; i < n; i += 2) {
        temp = max(temp, a[i]);
        ans++;
    }
    ans += temp;

    ll ans2 = 0;
    temp = INT_MIN;
    for(int i = 1; i < n; i += 2) {
        temp = max(temp, a[i]);
        ans2++;
    }
    ans2 += temp;
    cout << max(ans, ans2) << "\n";
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