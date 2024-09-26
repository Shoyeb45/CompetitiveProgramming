#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
ll d;
vector<ll> a;
void solve() {
    cin >> n >> d;
    a.resize(n);

    for(auto &x: a) {
        cin >> x;
    }

    sort(a.rbegin(), a.rend());

    int rem = n, ans = 0;

    for(int i = 0; i < n; i++) {
        ll needed = (d) / a[i] + 1;
        if(rem >= needed) {
            ans++;
            rem -= needed;
        }
        else {
            break;
        }
    }
    cout << ans << '\n';
}

int main() {
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}