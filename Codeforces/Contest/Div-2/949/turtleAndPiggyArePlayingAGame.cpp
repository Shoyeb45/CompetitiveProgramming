#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    ll l, r;
    cin >> l >> r;
    ll ans = 2;
    int cnt = 0;
    while(ans <= r) {
        ans *= 2;
        cnt++;
    }
    cout << cnt << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
