#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, k;
int dp[(int)(1e5 + 1)];
int f(vector<int> &a, int curr) {
    if(curr >= n - 1) {
        return 0;
    }

    if(dp[curr] != -1) {
        return dp[curr];
    }
    vector<int> mn(k, INT_MAX);
    for(int i = 1; i <= k; i++) {
        int newInd = curr + i;
        if(newInd < n) {
            mn[i - 1] = abs(a[curr] - a[newInd]) + f(a, newInd);
        }
    }


    return dp[curr] = *min_element(range(mn));
}
void solve() {
    cin >> n >> k;
    vector<int> a(n);
    loop(i, n) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));

    int ans = f(a, 0);
    cout << ans << '\n';
}

int main() {
    NFS
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
