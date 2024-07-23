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
    
    if(k == 0) {
        cout << 0 << '\n';
        return;
    }

    if(k <= n) {
        cout << 1 << '\n';
        return;
    }


    if(k == n * n) {
        cout << (2 * n) - 1 << '\n';
    } else {
        int ans = 1;
        k -= n;
        for(int i = n - 1; i >= 1; i--) {
            if(k >= i) {
                ans++;
                k -= i;
            } else {
                if(k != 0)
                ans++;
                break;
            }

            if(k >= i) {
                ans++;
                k -= i;
            } else {
                if(k != 0)
                ans++;
                break;
            }
        }
        cout << ans << '\n';
    }
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
