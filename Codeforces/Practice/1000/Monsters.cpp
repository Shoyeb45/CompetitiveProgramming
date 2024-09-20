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
    for(auto &x : a) {
        cin >> x;
    }
    sort(range(a));

    ll prev = 1, ans = 0;
    int i = 0;
    while(i < n) {
        if(prev == a[i]) {
            while(i < n - 1 && a[i] == a[i + 1]) {
                i++;
            }
        }
        ans += max(a[i] - prev, 1LL * 0);
        prev++;
        i++;
    }
    cout << ans << '\n';
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
