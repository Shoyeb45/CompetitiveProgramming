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
vector<int> h;
void solve() {
    cin >> n;
    h.resize(n);
    loop(i, n)
        cin >> h[i];
    
    int ans = h[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        ans = max(ans + 1, h[i]);
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
