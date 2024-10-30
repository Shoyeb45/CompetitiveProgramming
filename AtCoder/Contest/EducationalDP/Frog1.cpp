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
vector<int> a;

ll jump(vector<int> &a, int idx, vector<ll> &dp) {
    if(idx >= n - 1) {
        return 0;
    }

    if(dp[idx] != -1) {
        return dp[idx];
    }

    int x = abs(a[idx + 1] - a[idx]) + jump(a, idx + 1, dp);
    int y = INT_MAX;
    if(idx + 2 < n) {
        y = abs(a[idx + 2] - a[idx]) + jump(a, idx + 2, dp);
    }
    int ans = min(x, y);

    dp[idx] = ans;
    return ans;
}
void solve() {
    cin >> n;

    loop(i, n) {
        int x;
        cin >> x;
        a.push_back(x);
    }    
    vector<ll> dp(n + 1, -1);
    
    cout << jump(a, 0, dp) << '\n';
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while(tt--) {
        solve();
    }
    
    return 0;
}
