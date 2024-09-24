#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int dp[1004];
int n;
string s;

ll f(int idx) {
    if(idx >= n) {
        return INT_MIN;
    }

    if(s[idx] == 'w') {
        return INT_MIN;
    }

    if(idx == n - 1) {
        return 0;
    }

    if(dp[idx] != -1) {
        return dp[idx];
    }

    ll curr = (s[idx] == '\"');

    ll ans1 = curr + f(idx + 1);
    ll ans2 = curr + f(idx + 3);
    ll ans3 = curr + f(idx + 5);
    
    ll ans = max({ans1, ans2, ans3});

    return dp[idx] = ans;
}

void solve() {
    cin >> n;
    cin >> s;

    memset(dp, -1, sizeof(dp));

    ll ans = f(0);

    if(ans < 0) {
        ans = -1;
    }
    cout << ans << '\n';
}

int main() {
    NFS
    int tt;
    tt = 1;
    // cin >> tt;
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);

    while (tt--) {
        solve();
    }
    
    return 0;
}
