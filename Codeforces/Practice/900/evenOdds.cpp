#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;
ll n, k;
auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

void solve() {
    cin >> n >> k;
    ll idx = (n + 1)/2;

    if(k > idx) {
        cout << 2 * (k - idx) << '\n';
    } else {
        cout << 2 * (k) - 1 << '\n';
    }
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
 