#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int n, k;
void solve() {
    cin >> n >> k;
    vector<int> a(k);
    loop(i, k)
        cin >> a[i];
    sort(range(a));

    ll ans = 0;
    loop(i, k - 1) {
        ans += (2 * a[i] - 1);
    }
    cout << ans << '\n';
}

int main() {
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
