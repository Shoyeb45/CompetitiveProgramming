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
bool in_betw(ll x, ll l, ll r) {
    return (x >= l && x <= r);
}

int a, b, c, d;
void solve() {
    cin >> a >> b >> c >> d;

    cout << (((a >= b) == (c >= d)) ? "YES\n": "NO\n"); 
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
