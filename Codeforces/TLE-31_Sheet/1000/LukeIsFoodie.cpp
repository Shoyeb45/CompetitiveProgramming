#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, x;
vector<int> a;
void solve() {
    cin >> n >> x;
    a.resize(n);

    for(auto &x: a) {
        cin >> x;
    }
    int l = a[0] - x, r = a[0] + x;
    int ans = 0;

    for(int i = 1; i < n; i++) {
        l = max(l, a[i] - x), r = min(r, a[i] + x);
        if(l > r) {
            ans++;
            l = a[i] - x, r = a[i] + x;
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