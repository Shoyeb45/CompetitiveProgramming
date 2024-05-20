#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int x, y;
    cin >> x >> y;  
    
    int ans = 0;
    int rem = 0;
    int two = 0;
    if(y % 2) {
        two = (y)/2 + 1;
        rem = 7 * two + 4;
    } else {
        two = y/2;
        rem = 7 * two;
    }

    if(rem >= x) {
        ans += two;
    } else {
        x = x - rem;
        ans = two + (x + 14)/15;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}
