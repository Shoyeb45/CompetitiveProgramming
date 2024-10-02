#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n;
void solve() {
    cin >> n;
    string ans = "ROYGBIV";
    string temp = "GBIV";
    n -= 7;
    int j = 0;
    for(int i = 0; i < n; i++) {
        ans += temp[j++];
        if((i + 1) % 4 == 0) {
            j = 0;
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