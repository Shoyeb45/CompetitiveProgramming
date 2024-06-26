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

int x, y, k;
void solve() {
    cin >> x >> y >> k;
    while(x != 1) {
        int r = y - (x % y);
        if(r <= k) {
            k -= r;
            x += r;
        } else {
            cout << x + k << '\n';
            return;
        }
        while(x % y == 0) {
            x /= y;
        }
    }
    cout << (x + k % (y - 1)) << '\n';   
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
