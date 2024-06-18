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

int f(int n) {
    int ans = 1;
    while(n >= 1) {
        int digit = n % 10;
        if(digit != 0) {
            ans *= digit;
        }
        n /= 10;
    }
    return ans;
}

int g(int n) {
    
    while(n % 10 != n) {
        int temp = f(n);
        n = temp;
    }
    return n;
}

int l, r, k;
void solve() {
    cin >> l >> r >> k;
    int ans = 0;
    for(int i = l; i <= r; i++) {
        if(g(i) == k) {
            ans++;
        }
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
