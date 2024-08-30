#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int l, r;
void solve() {
    cin >> l >> r;
    vector<bool> ck(1002, 0);
    int ans = 0;
    for(int i = l; i <= r - 2; i++) {
        if(__gcd(i, i + 2) == 1 && !ck[i] && !ck[i + 1] && !ck[i + 2]) {
            ck[i] = ck[i + 1] = ck[i + 2] = 1;
            ans++;
        }
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
