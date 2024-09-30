#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
vector<ll> a;
void solve() {
    // Kadane's Algorithm

    cin >> n;
    a.resize(n);

    for(auto &x: a) {
        cin >> x;
    }

    ll ans = INT_MIN, currSum = 0;
    int prev = (a[0] < 0? -a[0] % 2 : a[0] % 2);
    for(auto x: a) {
        if(prev == (x < 0?  -x % 2: x % 2)) {
            currSum = 0;
        }

        prev = (x < 0? -x % 2 : x % 2);
        currSum += x;
        ans = max(ans, currSum);
        if(currSum < 0) {
            currSum = 0;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}