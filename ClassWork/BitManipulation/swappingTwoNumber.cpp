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

// Without using extra variable
void swap_num(ll &x, ll &y) {
    x = (x ^ y);
    y = (x ^ y);
    x = (x ^ y);
}

ll x, y;
void solve() {
    cin >> x >> y;
    cout << "Before\nx: " << x << " " << "y: " << y << '\n';

    swap_num(x, y);
    cout << "After\nx: " << x << " " << "y: " << y << '\n';
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
