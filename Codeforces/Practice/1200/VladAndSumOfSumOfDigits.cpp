#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;
#define MAX_SIZE 2e5 + 1

int dp[(int)MAX_SIZE];

void solve() {
    int n;
    cin >> n;
    cout << dp[n] << "\n";
}

int sumOfDigits(int x) {
    int ans = 0;

    while(x >= 1) {
        ans += (x % 10);
        x /= 10;
    }
    return ans;
}
int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    dp[1] = 1;
    for(int i = 1; i < (int)MAX_SIZE; i++) {
        dp[i] = dp[i - 1] + sumOfDigits(i);
    }

    while (tt--) {
        solve();
    }
    
    return 0;
}
