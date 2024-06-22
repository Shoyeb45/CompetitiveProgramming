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

bool is_set_bit(ll num, int pos) {
    return ((num >> pos) & 1) == 1;
}
int n, m;
void solve() {
    cin >> n >> m;
    int l = max(0, n - m);
    int r = n + m;

    ll val = 1;
    ll ans = 0;
    for(int i = 0; i <= 32; i++) {
        if(r - l >= val) 
            ans += val;
        else if(is_set_bit(l, i)) 
            ans += val;
        else if(is_set_bit(r, i))
            ans += val;
        val *= 2;
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
