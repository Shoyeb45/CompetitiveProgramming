#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
vector<int> a;
void solve() {
    cin >> n;
    a.resize(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> prefix(n + 1, 0), suffix(n + 1, 0);
    prefix[1] = a[1];
    for(int i = 2; i <= n; i++) {
        prefix[i] = __gcd(a[i], prefix[i - 1]);
    }

    suffix[n] = a[n];
    for(int i = n - 1; i >= 1; i--) {
        suffix[i] = __gcd(a[i], suffix[i + 1]);
    }

    int ans = 1;
    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            ans = max(ans, suffix[i + 1]);
        }   
        else if(i == n) {
            ans = max(ans, prefix[i - 1]);
        }
        else {
            ans = max(ans, __gcd(prefix[i - 1], suffix[i + 1]));
        }
    }
    cout << ans << "\n";
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
