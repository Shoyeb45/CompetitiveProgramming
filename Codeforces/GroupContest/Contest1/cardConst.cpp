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

int n;
void solve() {
    cin >> n;

    int ans = 0;
    while(n >= 2) {
        int cards = 0;
        for(int i = 1; ; i++) {
            cards = (i) * (3 * (i + 1) - 2) / 2;
            // cout << "c: "<< cards << '\n';
            if(cards > n) {
                i -= 1;
                n -= ((i) * (3 * (i + 1) - 2) / 2);
                // cout << "n: " << n <<'\n';
                break;
            } else if(cards == n ) {
                n -= cards;
                break;
            }
        }
        ans++;
        
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
