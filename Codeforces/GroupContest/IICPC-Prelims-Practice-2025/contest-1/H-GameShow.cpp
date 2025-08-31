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


void solve() {
    int n;
    cin >> n;
    int ans = 100, sum = 100;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        ans = max(ans, sum);
    }
    cout << ans << "\n";
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
